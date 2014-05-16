#if 0
#include "tepp/scheduler/scheduler_realtime.h"

namespace tepp
{
    scheduler_realtime::scheduler_realtime()        
        :m_waiting_thread(&scheduler_realtime::waiting_thread_run, 0)
    {
    }

    scheduler_realtime::~scheduler_realtime()
    {
        m_stopping = true;
        {
            std::lock_guard<std::recursive_mutex> l(m_tasks_access);
            m_tasks.clear();
        }
        m_timed_mutex.unlock();
        m_waiting_thread.join();
    }
    void scheduler_realtime::notify(const tp & )
    {}

    bool scheduler_realtime::remove(const scheduled_task::id & i)
    {
        bool reset;
        {
            std::lock_guard<std::recursive_mutex> l(m_tasks_access);
            container::iterator it = std::find_if(m_tasks.begin(), m_tasks.end(), [&](const container::value_type & sc){ return sc.second.identifier == i; });
            if (it == m_tasks.end())// may be already executed
                return false;

            reset = m_tasks.begin() == it;
            m_tasks.erase(it);

        }

        if (reset) // the scheduler has to be reseted
            m_timed_mutex.unlock();

        return true;
    }

    bool scheduler_realtime::task_empty()
    {
        std::lock_guard<std::recursive_mutex> l(m_tasks_access);
        return m_tasks.empty();
    }
    tp scheduler_realtime::now()const
    {
        return std::chrono::system_clock::now();
    }
    void scheduler_realtime::waiting_thread_run(int)
    {
        m_timed_mutex.lock();

        while (true)
        {

            while (task_empty())
                m_timed_mutex.lock();

            tp next_rendez_vous;

            m_tasks_access.lock();
            if (m_tasks.empty())
                continue;

            // m_tasks is locked and not empty, go ahead : wait or proceed
            next_rendez_vous = m_tasks.begin()->first;
            if (next_rendez_vous >= now())
            {
                scheduled_task s(std::move(m_tasks.begin()->second));
                m_tasks.erase(m_tasks.begin());
                if (s.recurrent.count() != 0)
                {
                    m_tasks.emplace(next_rendez_vous + s.recurrent, s);
                }
                m_tasks_access.unlock();
                s.task();
            }
            else
            {
                m_tasks_access.unlock();
                m_timed_mutex.try_lock_until(next_rendez_vous);
            }
        }
    }

}

#endif
