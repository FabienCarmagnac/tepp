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
        
        /* id_created will contain the id of the task. It is passed as reference because the task can remove the id directly via a lambda.
        If this id is returned, it should not be initialised before removed. */
        template < class Func, class ... Args > void add(scheduled_task::id& id_created, tp start, std::chrono::milliseconds && recurrent_milliseconds, Func && f, Args ... args)
        {
            return add_recurrent(id_created, std::move(start), std::move(recurrent_milliseconds), std::move(f), args ...);
        }
        template < class Func, class ... Args > void add_recurrent(scheduled_task::id& id_created, tp start, std::chrono::milliseconds && recurrent_milliseconds, Func && f, Args ... args)
        {
            id_created = ++m_last_id;
            std::function<void()> ff = [&]{f(args...); };
            scheduled_task sch(ff, id_created, recurrent_milliseconds);
            container::value_type toinsert = std::make_pair(start, sch);

            m_tasks.insert(toinsert);
            
            notify(m_last_now);
        }
        
        bool remove(const scheduled_task::id & i);
    };
}

#endif // TEPP_SCHEDULER_REPLAY_H

