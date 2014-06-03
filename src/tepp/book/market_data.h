#ifndef TEPP_BOOK_MARKET_DATA_H
#define TEPP_BOOK_MARKET_DATA_H

#include "tepp/gentypes.h"
#include "tepp/book/order_book_line.h"
#include "tepp/order/order.h"
#include "tepp/order/execution.h"
#include <tuple>

namespace tepp
{
    /* market data contract : 
    
    bool has_last()const
    bool can_create(const order & porder)const
    tp get_time()const
    size_t try_fill_execs(const order & order, execution_memory & execs)
    */

    class order_book_level1
    {
        order_book_line bid, ask, last;
    public:
        order_book_level1(const order_book_line & pbid, const order_book_line & pask, const order_book_line & plast)
            : bid(pbid), ask(pask), last(plast)
        {}
        order_book_level1(const order_book_line & pbid, const order_book_line & pask)
            : bid(pbid), ask(pask)
        {}
        bool has_last()const{ return last.get_time() >= bid.get_time() && last.get_time() >= ask.get_time(); }
        const order_book_line & get_ask() const{ return ask; }
        const order_book_line & get_bid() const{ return bid; }
        const order_book_line & get_last() const{ return last; }
        bool can_create(const order & porder)const
        {
            return (!porder.has_stop()) ||
                (
                (last.get_price() < porder.get_stop() && porder.get_side() == order_side::buyer) ||
                (last.get_price() > porder.get_stop() && porder.get_side() == order_side::seller)
                );
        }

        tp get_time()const
        {
            if (bid.get_time() > ask.get_time())
            {
                if (bid.get_time() > last.get_time())
                {
                    return bid.get_time();
                }
                else
                    return last.get_time();
            }
            else
            {
                if (ask.get_time() > last.get_time())
                {
                    return ask.get_time();
                }
                else
                    return last.get_time();
            }
        }
        void send_exec(price p, const order & porder, execution_memory & execs)const
        {
            execution_single exec(p, porder.get_qty(), get_time());
            execs.add_execution(exec);
        }
        size_t try_fill_execs(const order & porder, execution_memory & execs)const
        {
            if (execs.get_qty() >= porder.get_qty())
                return 0;

            switch (porder.get_kind())
            {
            case order_kind::market:
                //const order_book_line & ex = (porder.get_side() == order_side::buyer ? get_ask() : get_bid());
                send_exec((porder.get_side() == order_side::buyer ? get_ask() : get_bid()).get_price(), porder, execs);
                return 1;

            case order_kind::limit:
                if (porder.get_side() == order_side::buyer)
                {
                    if (get_ask().get_price() <= porder.get_limit())
                    {
                        send_exec(porder.get_limit(), porder, execs);
                        return 1;
                    }
                }
                else if (porder.get_side() == order_side::seller)
                {
                    if (get_bid().get_price() >= porder.get_limit())
                    {
                        send_exec(porder.get_limit(), porder, execs);
                        return 1;
                    }
                }
                break;

            case order_kind::stop:
                if (porder.get_side() == order_side::buyer && get_last().get_price() >= porder.get_stop())
                {
                    send_exec(get_ask().get_price(), porder, execs);
                    return 1;
                }
                else if (porder.get_side() == order_side::seller && get_last().get_price() <= porder.get_stop())
                {
                    send_exec(get_bid().get_price(), porder, execs);
                    return 1;
                }
                break;

            case order_kind::stop_limit:
                break;
            }
            return 0;
        }
    };


}

#endif // TEPP_BOOK_MARKET_DATA_H
