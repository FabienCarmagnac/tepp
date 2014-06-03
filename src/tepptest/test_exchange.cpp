#include "tepptest/helpers.h"
#include "tepp/market/exchange.h"

void test_exchange()
{
    tepp::exchange_fast lfast_exchange;
    tepp::exchange_slow lslow_exchange;
    tepp::exchange lexchange;

    CHECK_TRUE(lfast_exchange.transport_time < lexchange.transport_time);
    CHECK_TRUE(lexchange.transport_time < lslow_exchange.transport_time);


}
