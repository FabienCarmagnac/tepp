#ifndef TE_THREAD_POOL_H
#define TE_THREAD_POOL_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

namespace tepp
{

    class thread_pool 
    {
    public:
        thread_pool(size_t);
        template<class F, class... Args>
        auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;
        ~thread_pool();
    private:
        // need to keep track of threads so we can join them
        std::vector< std::thread > m_workers;
        // the task queue
        std::queue< std::function<void()> > m_tasks;

        // synchronization
        std::mutex m_queue_mutex;
        std::condition_variable m_condition;
        bool m_stop;
    };

// the constructor just launches some amount of m_workers
    inline thread_pool::thread_pool(size_t threads)
        :   m_stop(false)
    {
        for(size_t i = 0; i<threads; ++i)
            m_workers.emplace_back(
                [this]
        {
            while(true)
            {
                std::unique_lock<std::mutex> lock(this->m_queue_mutex);
                while(!this->m_stop && this->m_tasks.empty())
                    this->m_condition.wait(lock);
                if(this->m_stop && this->m_tasks.empty())
                    return;

                // here : unlock
                // this block should be protected by an atomic transaction
                std::function<void()> task(this->m_tasks.front());
                this->m_tasks.pop();
                // end, remove lock
                lock.unlock();
                task();
            }
        }
        );
    }

// add new work item to the pool
    template<class F, class... Args>
    auto thread_pool::enqueue(F&& f, Args&&... args)
    -> std::future<typename std::result_of<F(Args...)>::type>
    {
        typedef typename std::result_of<F(Args...)>::type return_type;

        // don't allow enqueueing after m_stopping the pool
        if(m_stop)
            throw std::runtime_error("enqueue on m_stopped thread_pool");

        auto task = std::make_shared< std::packaged_task<return_type()> >(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock(m_queue_mutex);
            m_tasks.push([task]()
            {
                (*task)();
            });
        }
        m_condition.notify_one();
        return res;
    }

// the destructor joins all threads
    inline thread_pool::~thread_pool()
    {
        {
            std::unique_lock<std::mutex> lock(m_queue_mutex);
            m_stop = true;
        }
        m_condition.notify_all();
        for(size_t i = 0; i<m_workers.size(); ++i)
            m_workers[i].join();
    }

}

#endif
