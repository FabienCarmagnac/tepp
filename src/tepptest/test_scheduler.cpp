#include "tepptest/helpers.h"
#include "tepp/scheduler/scheduler_replay.h"


int i = 0;
void p(){ std::cout << (++i) << std::endl; }
void test_scheduler_replay()
{

    // simulated
    using namespace std::chrono;

    tepp::scheduler_replay sched;
    
    int i0(-1), i1(-1), i2(-1), i3(-1);
    std::function<void()> i0_target = [&](){i0 = 0; };

    tepp::tp start_tp;
    
    start_tp += std::chrono::minutes(1);
    auto i0_id = sched.add_recurrent(start_tp, std::chrono::milliseconds(1000), i0_target);
    sched.notify(start_tp);
    CHECK_EQUAL(i0, 0);
    i0 = -1;
    sched.notify(start_tp += std::chrono::milliseconds(1000));
    CHECK_EQUAL(i0, 0);
    i0 = -1;
    sched.notify(start_tp += std::chrono::milliseconds(500));
    CHECK_EQUAL(i0, -1);
    sched.notify(start_tp += std::chrono::milliseconds(500));
    CHECK_EQUAL(i0, 0);
    i0 = -1;
    CHECK_TRUE(sched.remove(i0_id));
    sched.notify(start_tp += std::chrono::milliseconds(1000));
    CHECK_EQUAL(i0, -1);


    auto i1_target = [&](){++i1; };

    sched.add(start_tp, std::chrono::milliseconds(1), i1_target);
    CHECK_EQUAL(i1, 0);
    for (int i = 0; i < 10; i++)
    {
        CHECK_EQUAL(i1, i);
        sched.notify(start_tp += std::chrono::milliseconds(1));
    }
    CHECK_EQUAL(i1, 10);
    sched.notify(start_tp += std::chrono::milliseconds(10));
    CHECK_EQUAL(i1, 20);
    sched.notify(start_tp);
    sched.notify(start_tp);
    sched.notify(start_tp);
    sched.notify(start_tp);
    CHECK_EQUAL(i1, 20);


}
