#ifndef TE_EVENTS_H
#define TE_EVENTS_H

#include <functional>
#include <list>
#include <array>
#include <algorithm>

#include "tepp/import_export.h"

#include "tepp/thread_pool.h"

namespace tepp
{

    template <class source_t> class TE_API event_generator
    {
        typedef typename std::function<int(source_t &)>  notify_function;
        typedef typename source_t::events events;
        typedef typename std::list<notify_function> f_container;
        typedef std::array< f_container, static_cast<int>(events::last_event)  > array_of_clients;
        array_of_clients m_clients;

        source_t & m_source;
    public:
        typedef typename f_container::iterator subscription_id;

        event_generator(source_t & source)
            : m_source(source)
        {
        }

        template < int Event > subscription_id subscribe(notify_function f)
        {
            f_container & li = m_clients[Event];
            li.push_back(f);
            return --(li.end());
        }
        template < int Event > subscription_id subscribe(notify_function f, thread_pool & t)
        {
            f_container & li = m_clients[Event];
            notify_function f_async = [&t, &f](source_t & st){ t.enqueue(f, st); return 0; };
            li.push_back(f_async);
            return --(li.end());
        }
        template < int Event > bool unsubscribe(subscription_id i)
        {
            f_container & li = m_clients[Event];
            li.erase(i) > 0;
        }

        template < int Event > void notify()
        {
            f_container & li = m_clients[Event];
            for_each(li.begin(), li.end(), [this](notify_function & f){f(m_source); });
        }
    };

}//ns

#endif // TE_EVENTS_H


