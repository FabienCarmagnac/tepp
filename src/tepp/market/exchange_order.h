#ifndef TEPP_MARKET_EXCHANGE_ORDER_H
#define TEPP_MARKET_EXCHANGE_ORDER_H

#include <chrono>
#include <forward_list>
#include <string>
#include "tepp/market/exchange.h"
#include "tepp/logger.h"
#include "tepp/order/order.h"
#include "tepp/order/execution.h"
#include "tepp/datetime.h"


namespace tepp
{
    template < class market_data_t > class order_exchange
    {
        enum class event_t : char
        {
            creation_request_arrived_on_exchange = 'a',
            creation_process,
            creation_ack_send,
            creation_rej_send,
            cancel_request_arrived_on_exchange,
            cancel_process,
            cancel_ack_send,
            cancel_rej_send,
            exec_send
            /*
            creation_request_arrived_on_exchange = 'a',
            creation_process                     = 'b',
            creation_ack_send                    = 'c',
            creation_rej_send                    = 'd',
            cancel_request_arrived_on_exchange   = 'e',
            cancel_process                       = 'f',
            cancel_ack_send                      = 'g',
            cancel_rej_send                      = 'h',
            exec_send                            = 'i'
            */
        };

        order & m_order;
        order_status m_exchange_status = order_status::created;

        
        size_t m_size = 0;

        struct time_event_t
        {
            time_event_t(tp p_t, event_t p_ev) :t(p_t), ev(p_ev){}
            tp t;
            event_t ev;
        };

        typedef std::forward_list<time_event_t> container;
        container m_evts;

        execution_memory m_execs;
        size_t m_exec_index = 0;
    
        // returns end() if should be emplaced front.
        void where_to_insert(tp t, typename container::iterator & i)
        {
            if (m_size == 0)
                return;

            container::iterator b = m_evts.begin();
            while (b != m_evts.end() && b->t <= t)
            {
                i = b;
                ++b;
            }
            // assert(i == m_evts.end() && "while trying to insert: cannot insert  first when m_evts is not empty !");
        }

    public:

        order_exchange(tp t, order & p_order)
            : m_order(p_order)
        {
            // when order arrives on market
            schedule_event(t + exchange::transport_time(), event_t::creation_request_arrived_on_exchange);
        }

        order_status get_status()const{ return m_exchange_status; }

        void cancel_request(tp t)
        {
            schedule_event(t + exchange::transport_time(), event_t::cancel_request_arrived_on_exchange);
        }

        void on_event(const market_data_t & md)
        {

            while (m_size != 0 &&
                m_evts.begin()->t <= md.get_time())
            {
                time_event_t time_event = *m_evts.begin();
                m_evts.pop_front();
                --m_size;
                process_event(time_event, md);
            }

            // events done, try exec
            if (is_executable_on_exchange(m_exchange_status))
                try_exec(md);
        }

    private:

        void try_exec(const market_data_t & md, const tp * t=nullptr)
        {
            int n = md.try_fill_execs(m_order, m_execs);
            if (n == 0)
                return;
            
            tp time = (t == nullptr ? md.get_time() : *t);
            while (--n >= 0)
            {
                TRACE_T("try_exec", time, "EXEC : " << m_execs.get_execs()[m_execs.get_execs().size() - n - 1]);
                schedule_event(time + exchange::transport_time_on_exec(), event_t::exec_send);
            }

            if (m_execs.get_qty() < m_order.get_qty())
                m_exchange_status = order_status::part_executed;
            else
                m_exchange_status = order_status::executed;
        }

        void schedule_event(tp t, event_t ev)
        {
            TRACE_("order_exchange", "scheduling event " << ((char)ev) << " at " << tptostr(t));
            container::iterator i = m_evts.end();
            where_to_insert(t, i);
            if (i == m_evts.end())
                m_evts.emplace_front(t, ev);
            else
                m_evts.emplace_after(i, t, ev);
            m_size++;

        }

        void process_event(const time_event_t & e, const market_data_t & md)
        {
            TRACE_("process event", "event " << ((char)e.ev) << " at " << tptostr(e.t) << ", data t : " << tptostr(md.get_time()));
            switch (e.ev)
            {
                // CREATION

            case event_t::creation_request_arrived_on_exchange:
                // order arrived 'physically' to the exchange
                assert(m_exchange_status == order_status::created && "status should be 'created'");
                m_exchange_status = order_status::pending_sent;
                schedule_event(e.t + exchange::processing_time_creation_request(), event_t::creation_process);
                break;

            case event_t::creation_process:
                // order processed new/rejected
                assert(m_exchange_status == order_status::pending_sent && "status should be 'pending_sent'");

                if (md.can_create(m_order))
                {
                    m_exchange_status = order_status::working;
                    // working now, so we try to exec
                    try_exec(md, &(e.t));
                    schedule_event(e.t + exchange::transport_time(), event_t::creation_ack_send);
                }
                else
                {
                    m_exchange_status = order_status::rejected;
                    schedule_event(e.t + exchange::transport_time() , event_t::creation_rej_send);
                }
                break;

            case event_t::creation_rej_send:
                m_order.on_event(order_status::rejected);
                break;

            case event_t::creation_ack_send:
                m_order.on_event(order_status::working);
                break;


                // CANCEL


            case event_t::cancel_request_arrived_on_exchange:
                schedule_event(e.t + exchange::processing_time_cancel_request(), event_t::cancel_process);
                break;

            case event_t::cancel_process:
                // try processing now the cancelation
            {
                bool cancelable = is_cancelable(m_exchange_status);
                if (cancelable)
                    m_exchange_status = order_status::canceled;

                schedule_event(e.t + exchange::transport_time(),
                    cancelable ? event_t::cancel_ack_send : event_t::cancel_rej_send);
            }
                break;

            case event_t::cancel_ack_send:
                assert(m_exchange_status == order_status::canceled && "status should be 'canceled'"); // terminal
                m_order.on_event(order_status::canceled);
                break;

            case event_t::cancel_rej_send:
                m_order.on_event(order_status::rejected);
                break;

                // EXEC

            case event_t::exec_send:
                assert(m_exec_index < m_execs.get_execs().size());
                m_order.on_event(m_execs.get_execs()[m_exec_index]);
                
                if (m_execs.get_qty() < m_order.get_qty())
                    m_order.on_event(order_status::part_executed);
                else
                    m_order.on_event(order_status::executed);
                ++m_exec_index;
                break;


            default:
                break;
            };

        }
    };
}

#endif //TEPP_MARKET_EXCHANGE_ORDER_H
