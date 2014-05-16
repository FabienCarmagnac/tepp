#ifndef TEPP_ORDER_VIRTUAL_MARKET_H
#define TEPP_ORDER_VIRTUAL_MARKET_H

#include <list>
#include "tepp/order/order.h"

namespace tepp
{
    /*
    
    order :

    sent with creation_time : created
    after some time, on market data: 
        working_on_market -> on_time_to_working
        rejected_on_market -> on_time_to_reject : send notify

    then, from working:

        execution_available -> execution_callbacked -> closed
        
        deletion_requested : deletion_callbacked

    or owner initiates "cancel"

        cancel_requested -> canceling_on_market

        canceling_on_market -> canceled_callbacked : send notify

    */

    template < class order_t, class market_data > class order_wrapper
    {
        typedef std::function<callback(const market_data & , bool&)> callback_t;
        callback_t m_callback = working_on_market;
        order_t & m_order;
        tp m_trigger;
        std::vector<single_execution> m_pending_exec;
        std::vector<single_execution>::iterator m_current_exec_index;
        static std::array< callback_t, order_kind::enum_count> s_automaton
            = { working_market_order, working_limit_order, working_stop_order, working_stop_limit_order };

    public:

        order_wrapper(tp start_time, const order_t & order)
            : m_order(order)
        {
            // when order arrives on market
            m_trigger = start_time + global_market_round_trip_time();
        }
        

        void on_event(const & market_data md, tp & event_next)
        {
            if (m_trigger <= md.get_time() && m_callback != nullptr)
            {
                callback_t next;
                m_callback(md, next);
                m_callback = next;
            }
        }

    protected:

        /* buy / sell */
        void on_time_to_full_exec_buy(const & market_data md, callback_t & next);
        {
            fill_execs< order_side::buyer >(m_pending_exec);
            on_time_to_full_exec(md, next = on_time_to_full_exec_buy);
        }
        void on_time_to_full_exec_sell(const & market_data md, callback_t & next);
        {
            fill_execs< order_side::seller >(m_pending_exec);
            on_time_to_full_exec(md, next = on_time_to_full_exec_sell);
        }
        
        /* neutral exec */
        void on_time_to_full_exec_init(const & market_data md, callback_t & next);
        {
            if (m_pending_exec.empty())
            {
                m_trigger = md.get_time();
            }
            else
            {
                m_current_exec_index = m_pending_exec.begin();
                on_time_to_send_exec(md, next);
            }
        }
        
        
        void on_time_to_send_exec(const & market_data md, callback_t & next)
        {
            m_order.on_execution(*m_current_exec_index);
            ++m_current_exec_index;
            if (m_current_exec_index == m_order.end())
            {
                if(m_order.qty_left()==0)
                    next = nullptr;
            else
            {
                next = on_time_to_send_exec;
                m_trigger += global_market_internal_tick();
            }
        }

        /* market */
        void working_market_order(const & market_data md, callback_t & next)
        {
            // time for answer to reach destination
            m_trigger += global_market_round_trip_time();
            next = on_time_to_new_market;
        }
        void on_time_to_new_market(const & market_data md, callback_t & next)
        {
            // time for answer to reach destination
            m_trigger += global_market_round_trip_time();
            m_order.notify_status_changed(order_t::status::working);
            next = on_time_to_full_exec[order.get_side()];
        }
        void on_time_to_full_exec(const & market_data md, callback_t & next)
        {
            if ()
        }




        void working_stop_order(const & market_data md, callback_t & next)
        {
            // time for answer to reach destination
            m_trigger += global_market_round_trip_time();
            if (!is_stop_entry(md, order)
            {
                next = on_time_to_reject;
            }
            else
                next = on_time_to_ask_stop;
        }


        void on_time_to_reject(const & market_data md, callback_t & next)
        {
            m_order.notify_status_changed(order_t::status::rejected);
            next = nullptr;
        }
        void on_time_to_working(const & market_data md, callback_t & next)
        {
            m_order.notify_status_changed(order_t::status::working);
            next = on_working_waiting_event;
        }
        void on_working_waiting_event(const & market_data md, callback_t & next)
        {
            if (order.get_kind() == order_t::kind::market)
            {

            }

        }
        callback_t working_on_market(const & market_data md, callback_t & next)
        {

        }
        callback_t working_on_market(const & market_data md, callback_t & next)
        {

        }
        callback_t working_on_market(const & market_data md, callback_t & next)
        {

        }
        callback_t working_on_market(const & market_data md, callback_t & next)
        {

        }
        callback_t working_on_market(const & market_data md, callback_t & next)
        {

        }
        callback_t working_on_market(const & market_data md, callback_t & next)
        {

        }
        callback_t working_on_market(const & market_data md, callback_t & next)
        {

        }


        callback closed(const & market_data md, bool & need_redo)
        {
            m_callback = nullptr;
        }

       /* enum market_order_status
        {
            working_on_market,
            on_time_to_working,
            rejected_on_market,
            on_time_to_reject,
            execution_available,
            execution_callbacked,
            deletion_requested,

        };*/

        


    };


    template < class market_data, class instrument_t, class order_owner_t  > class virtual_market
    {
        typedef order<instrument_t, order_owner_t> this_order;
        typedef std::list< this_order > container;
        container m_orders;

        std::vector< container::iterator > tmp_executed;


        

    public:
        
        void on_new_market_data(const market_data & md)
        {
            for (container::iterator it = m_orders.begin(); it != m_orders.end(); )
            {
                if (execution_occurs(*it, md))
                {
                    tmp_executed.push_back(it);
                }
            }

            foreach(container::iterator & it : tmp_executed)
            {
                it->get_owner().on_execution(*it);
            }

        }

    protected:
        static bool test_execution(this_order & p_order, execution & exec)
        {
            if (p_order.get_kind() == stop && )
            {

            }
        }

    };
}
#endif // TEPP_ORDER_VIRTUAL_MARKET_H

