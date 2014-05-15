#include "tepptest/helpers.h"
#include "tepp/stdstat.h"

void test_stdstat()
{
    tepp::stdstat stat("test");
    stat.add({ 1.0, 2, 3, 4, 5, 6, -1, -1000 });

    CHECK_EQUAL(stat.sum(), -980);
    CHECK_EQUAL(stat.sum2(), 1000092);
    CHECK_EQUAL(stat.stddev(), 331.67039361390096);
    CHECK_EQUAL(stat.minV(), -1000);
    CHECK_EQUAL(stat.maxV(), 6);
    CHECK_EQUAL(stat.absmax(), 1000);
    CHECK_EQUAL(stat.absmin(), 1);
    CHECK_EQUAL(stat.avg(), -122.5);

}

