#include "tepptest/helpers.h"
#include "tepp/market/exchange_order.h"
#include "tepp/instrument.h"
#include "tepp/book/market_data.h"

using namespace tepp;

void test_exchange_order()
{
    qty p_qty = 5;
    order_kind p_kind = order_kind::limit;
    order_side p_side = order_side::seller;
    instrument p_i;

    tp t = tp() + std::chrono::milliseconds(1000);

    order o_limit(p_qty, order_kind::limit, order_side::buyer, p_i, 100);
    order_exchange<order_book_level1> oe_limit(tp(), o_limit);
    
    order_book_line bid(99, 5, t);
    order_book_line ask(100, 10, t);
    order_book_line last(100.0, 5, t);

    order_book_level1 bookl1(bid, ask, last);

    oe_limit.on_event(bookl1);

    CHECK_EQUAL(o_limit.get_status(), order_status::executed);



    /*
    order o_stop(p_qty, order_kind::stop, order_side::buyer, p_i, 101);
    order o_market(p_qty, order_kind::market, order_side::buyer, p_i);
    order o_stop_limit(p_qty, order_kind::stop_limit, order_side::buyer, p_i, 104, 104.25);

    order_exchange<order_book_level1> oe_limit(t, o_limit);
    order_exchange<order_book_level1> oe_stop(t, o_stop);
    order_exchange<order_book_level1> oe_market(t, o_market);
    order_exchange<order_book_level1> oe_stop_limit(t, o_stop_limit);

    for (int i = 0; i < 100; i++)
    {
        t += std::chrono::milliseconds(100);

        order_book_line bid(100.0  + i*0.1,  5, t);
        order_book_line ask(100.1  + i*0.1, 10, t);
        order_book_line last(100.0 + i*0.1,  5, t);

        order_book_level1 bookl1(bid, ask);

        oe_limit.on_event(bookl1);
        oe_stop.on_event(bookl1);
        oe_market.on_event(bookl1);
        oe_stop_limit.on_event(bookl1);
    }
    
    */


}