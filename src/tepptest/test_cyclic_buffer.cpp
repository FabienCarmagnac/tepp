#include "tepptest/helpers.h"
#include "tepp/cyclic_buffer.h"
#include <algorithm>

void test_cyclic_buffer()
{
    tepp::cyclic_buffer<size_t> c(10);
    for (size_t i = 1; i < 100; i++)
    {
        c.add(i);
        CHECK_EQUAL(c.size(), std::min(i, c.capacity()));
        for (size_t j = 0; j < c.size(); j++)
        {
            CHECK_EQUAL(c.at(j), i - j);
        }

        tepp::cyclic_buffer<size_t>::iterator it = c.begin(), e = c.end();
        for (size_t j = 0; it != e; ++j, ++it)
        {
            CHECK_EQUAL(*it, i - j);
            CHECK_EQUAL(c.begin()[0], c[0]);
        }

    }
}
