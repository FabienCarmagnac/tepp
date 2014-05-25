#include "tepptest/helpers.h"
#include "tepp/market/exchange.h"

void test_exchange()
{
    tepp::fast_exchange lfast_exchange;
    tepp::slow_exchange lslow_exchange;
    tepp::exchange lexchange;

    CHECK_TRUE(lfast_exchange.transport_time() < lexchange.transport_time());
    CHECK_TRUE(lexchange.transport_time() < lslow_exchange.transport_time());
}
