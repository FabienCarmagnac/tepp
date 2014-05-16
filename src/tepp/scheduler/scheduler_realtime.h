#ifndef TEPP_SCHEDULER_H
#define TEPP_SCHEDULER_H

#include <thread>
#include <mutex>
#include <map>
#include <algorithm>

#include "tepp/scheduler/scheduled_task.h"
#include "tepp/gentypes.h"

namespace tepp
{

    class scheduler_realtime
    {
        
        /* store single scheduled task */
        typedef std::multimap< tp, scheduled_task > container;

        std::thread m_waiting_thread;
        std::timed_mutex m_timed_mutex;
        std::recursive_mutex m_tasks_access;

        scheduled_task::id m_last_id = 0;
        scheduled_task::id get_next_id(){ return ++m_last_id; }

        bool m_stopping = false;
        container m_tasks;

    public:

        scheduler_realtime();
        ~scheduler_realtime();

        /* Real time: do nothing but ensure compatibility with scheduler_replay */
        void notify(const tp &);

        template < class Func > scheduled_task::id add(Func && f, const tp & start, std::chrono::milliseconds recurrent_milliseconds)
        {
            bool reset;
            {
                std::lock_guard<std::recursive_mutex> l(m_tasks_access);
                id ret = get_next_id();
                reset = m_tasks.empty() || start <= m_tasks.begin()->first;
                m_tasks.emplace(
                    std::make_pair(
                    start,
                    scheduled([](){ f(); }, ret, recurrent_milliseconds)
                    )
                    );
            }

            if (reset)
                m_timed_mutex.unlock();

            return ret;
        }

        bool remove(const scheduled_task::id & i);

    private:

        tp now()const;
        bool task_empty();
        void waiting_thread_run(int);


    };

}




#endif // TEPP_SCHEDULER_H

