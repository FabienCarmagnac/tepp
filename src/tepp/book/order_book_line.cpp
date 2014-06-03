#include "tepp/book/order_book_line.h"

namespace tepp
{
    order_book_line::order_book_line()
    {}
    order_book_line::order_book_line(price ppx, qty pq, tp pt)
        :px(ppx), q(pq), t(pt)
    {}

    price order_book_line::get_price()const
    {
        return px;
    }
    qty order_book_line::get_qty()const
    {
        return q;
    }
    tp order_book_line::get_time()const
    {
        return t;
    }
}