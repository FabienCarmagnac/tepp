#ifndef TEPP_ORDER_ORDERBOOKLINE_H
#define TEPP_ORDER_ORDERBOOKLINE_H

#include "tepp/gentypes.h"

namespace tepp
{

    class order_book_line
    {
        price px;
        qty q;
        tp t;
    public:
        order_book_line();
        order_book_line(price ppx, qty pq, tp pt);

        price get_price()const;
        qty get_qty()const;
        tp get_time()const;

        //std::ostream & print(std::ostream & os)const;
    };


}

#endif // TEPP_ORDER_ORDERBOOKLINE_H

