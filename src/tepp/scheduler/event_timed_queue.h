#ifndef TEPP_SCHEDULER_EVENT_TIMED_QUEUE
#define TEPP_SCHEDULER_EVENT_TIMED_QUEUE

#include "tepp/gentypes.h"
#include "tepp/datetime.h"

#include <forward_list>

namespace tepp
{

    template < class object_t, class event_args_t > class event_timed_queue
    {
        typedef void (object_t::*on_event_t)(const event_args_t &);

        class local_event 
        {
        public:
            local_event(on_event_t ptask, tp prendezvous, object_t * pinstance)
                :task(ptask), rendezvous(prendezvous), instance(pinstance)
            {}
            on_event_t task;
            tp rendezvous;
            object_t * instance;
            void exec(const event_args_t & data)
            {
                (instance->*(task))(data);
            }
        };

        typedef std::forward_list<local_event> container;
        container m_seq;
        std::size_t m_size = 0;
        tp m_current_time = milliseconds_t(0);
    public:

        void on_event(const event_args_t & data)
        {
            tp stop_time = data.get_time();
            while (m_size > 0
                && m_seq.begin()->rendezvous <= stop_time)
            {
                //std::cout << m_size << "," << m_seq.begin()->rendezvous << ", stop=" << stop_time << std::endl;
                local_event lc = *m_seq.begin();
                m_current_time = lc.rendezvous;
                m_seq.pop_front();
                --m_size;
                lc.exec(data);
                //if (m_size>0) std::cout << m_size << "," << m_seq.begin()->rendezvous << ", stop=" << stop_time << std::endl;
            }
            m_current_time = stop_time;
        }
        size_t size()const
        {
            return m_size;
        }
        tp get_time()const
        {
            return m_current_time;
        }
        void emplace(on_event_t p_task, tp p_rendezvous, object_t * instance)
        {
           // std::cout << "queue: adding at " << p_rendezvous << std::endl;
            if (p_rendezvous <= m_current_time)
                throw std::runtime_error("too late to add at that time");

            ++m_size;
            if (m_size == 1)
            {
                m_seq.emplace_front(p_task, p_rendezvous, instance);
                return;
            }

            container::iterator it = m_seq.begin();
            container::iterator next = ++m_seq.begin();
            if (m_size == 2)
            {
                if (p_rendezvous < it->rendezvous)
                    m_seq.emplace_front(p_task, p_rendezvous, instance);
                else
                    m_seq.emplace_after(it, p_task, p_rendezvous, instance);
                return;
            }

            for (; next != m_seq.end() && next->rendezvous < p_rendezvous; ++next, ++it);
            m_seq.emplace_after(it, p_task, p_rendezvous, instance);

        }
    };
}
#endif // TEPP_SCHEDULER_EVENT_TIMED_QUEUE

