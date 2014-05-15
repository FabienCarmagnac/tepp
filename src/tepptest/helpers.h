#ifndef TEPPTEST_HELPERS_H
#define TEPPTEST_HELPERS_H

#include <iostream>

#define CHECK_EQUAL(x, y) try { auto xx=x; auto yy=y; if(xx!=yy) \
    std::cout << "Equal failed : in file " << __FILE__ << ":" << __LINE__ << ":" << std::endl << "\t" << #x << "='" << xx << "', should be \n\t" << #y << "='" << yy << "'" << std::endl; } \
    catch (...){ std::cout << "Test failed : exception thrown in file " << __FILE__ << ":" << __LINE__ << std::endl << "'" << #x << "' == '" << #y << "'" << std::endl; }

#define CHECK_TRUE(x) try { auto xx=x; if(!(xx)) \
    std::cout << "Test failed : in file " << __FILE__ << ":" << __LINE__ << ":" << std::endl << "\t" << #x << "=" << xx << ", should be true" << std::endl; } \
    catch (...){ std::cout << "Test failed : exception thrown in file " << __FILE__ << ":" << __LINE__ << std::endl << #x << std::endl; }



void test_cyclic_buffer();
void test_datetime();
void test_env();
void test_read_csv();
void test_stdstat();
void test_string_tools();
void test_scheduler_replay();


#endif // TEPPTEST_HELPERS_H

