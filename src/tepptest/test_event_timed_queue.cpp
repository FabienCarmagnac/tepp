#include "tepptest/helpers.h"
#include "tepp/scheduler/event_timed_queue.h"

using namespace tepp;

class base_arg
{
    tp m_tp = std::chrono::system_clock::now();
public:
    tp get_time()const{ return m_tp; }
    void inc(int millis)
    {
        m_tp += std::chrono::milliseconds(millis);
    }
};

class base_test
{

public:
    int i=0;
    typedef tepp::event_timed_queue<base_test, base_arg> queue_t;
    queue_t & queue;
    base_test(queue_t & p_queue) :queue(p_queue){}
    template < int int_value> void t_x(const base_arg & ba)
    {
        if (int_value >= 3)
        {
            i++;
            queue.emplace(&base_test::t_x<4>, queue.get_time() + std::chrono::milliseconds(100), this);
        }
        else
        {
            i = int_value;
        }
    }

};

void test_event_timed_queue()
{
    base_test::queue_t queue;
    base_arg ba;
    base_test bt(queue);

    queue.on_event(ba);
    queue.emplace(&base_test::t_x<1>, ba.get_time() + std::chrono::milliseconds(1000), &bt);
    queue.emplace(&base_test::t_x<2>, ba.get_time() + std::chrono::milliseconds(2000), &bt);
    queue.emplace(&base_test::t_x<3>, ba.get_time() + std::chrono::milliseconds(3000), &bt);
    
    CHECK_EQUAL(bt.i, 0);
    queue.on_event(ba);
    CHECK_EQUAL(bt.queue.size(), 3);

    ba.inc(500); 
    CHECK_EQUAL(bt.i, 0);
    queue.on_event(ba);

    ba.inc(500);
    CHECK_EQUAL(bt.queue.size(), 3);

    queue.on_event(ba); // f<1>
    CHECK_EQUAL(bt.i, 1);
    CHECK_EQUAL(bt.queue.size(), 2);

    // +1s

    ba.inc(100);
    queue.on_event(ba);
    CHECK_EQUAL(bt.i, 1);
    CHECK_EQUAL(bt.queue.size(), 2);

    // +1'1s

    ba.inc(1000);
    queue.on_event(ba);
    CHECK_EQUAL(bt.i, 2);
    CHECK_EQUAL(bt.queue.size(), 1);

    // +2'1s

    ba.inc(2000);
    queue.on_event(ba);
    CHECK_EQUAL(bt.i, 14);
    CHECK_EQUAL(bt.queue.size(), 1);

    // +3'1s

    ba.inc(1000);
    queue.on_event(ba);
    CHECK_EQUAL(bt.i,24);
    


}



