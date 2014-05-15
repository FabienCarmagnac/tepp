#ifndef TEPP_SCHEDULER_REPLAY_H
#define TEPP_SCHEDULER_REPLAY_H

#include <map>
#include <algorithm>

#include "tepp/scheduler/scheduled_task.h"
#include "tepp/gentypes.h"

namespace tepp
{

    /* This scheduler is mono-thread, since time is emulated. */

    class scheduler_replay
    {
        scheduled_task::id m_last_id = 0;
        typedef std::multimap< tp, scheduled_task > container;
        container m_tasks;
        tp m_last_now;
    public:

        void notify(const tp & now);
        
        template < class Func, class ... Args > scheduled_task::id add(tp start, std::chrono::milliseconds && recurrent_milliseconds, Func && f, Args ... args)
        {
            return add_recurrent(std::move(start), std::move(recurrent_milliseconds), std::move(f), args ...);
        }
        template < class Func, class ... Args > scheduled_task::id add_recurrent(tp start, std::chrono::milliseconds && recurrent_milliseconds, Func && f, Args ... args)
        {
            scheduled_task::id ret = ++m_last_id;
            std::function<void()> ff = [&]{f(args...); };
            scheduled_task sch(ff, ret, recurrent_milliseconds);
            container::value_type toinsert = std::make_pair(start, sch);

            m_tasks.insert(toinsert);
            
            notify(m_last_now);
            return ret;
        }
        
        bool remove(const scheduled_task::id & i);
    };
}

#endif // TEPP_SCHEDULER_REPLAY_H

