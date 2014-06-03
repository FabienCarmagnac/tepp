#include "tepptest/helpers.h"

#include <iostream>

// run all tests
int main(int argc, char **argv)
{
	std::cout<<"===BEGIN==="<< std::endl;
    test_cyclic_buffer();
    test_datetime();
    test_env();
    test_read_csv();
    test_stdstat();
    test_string_tools();
    test_scheduler_replay();
    test_event_timed_queue();
    test_exchange_order();

	std::cout<<"===END==="<< std::endl;
    getchar();
}
