#include "tepp/scheduler/scheduler_replay.h"

namespace tepp
{



    void scheduler_replay::notify(const tp & now)
    {
        if (m_last_now != now)
            m_last_now = now;

        while (!m_tasks.empty()
            && m_tasks.begin()->first <= now)
        {
            scheduled_task t(m_tasks.begin()->second);
            if (t.recurrent.count() != 0)
                m_tasks.insert(std::make_pair(t.recurrent + m_tasks.begin()->first, t));
            m_tasks.erase(m_tasks.begin());
            t.task();
        }
    }

    bool scheduler_replay::remove(const scheduled_task::id & i)
    {
        container::iterator it = std::find_if(m_tasks.begin(), m_tasks.end(), [&](container::value_type & sc){ return sc.second.identifier == i; });
        if (it != m_tasks.end())
        {
            m_tasks.erase(it);
            return true;
        }
        return false;
    }



}


