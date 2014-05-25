#ifndef TEPP_ORDER_H
#define TEPP_ORDER_H

#include <cstdint>
#include "tepp/order/execution.h"
#include "tepp/gentypes.h"

namespace tepp
{
    class instrument;
    class execution_aggregated;
    class order;

    enum order_side : char { buyer=0, seller=1 };
    enum order_status : char { created = 0, working = 1, part_executed = 2, executed = 4, canceled = 8, rejected = 16, deleted = 32 };
    enum order_kind : char { market=0, limit =1, stop=2, stop_limit=3 }; // stop_limit == stop | limit

    class order_owner
    {
    public:
        void on_event(order_status status, order & porder)
        {}
    };

    class order
    {

    public:

        order(qty p_qty, order_kind p_kind, order_side p_side, tp p_creation_time, const instrument & p_instrument);

        bool terminated()const;
        qty get_qty() const;
        order_status get_status()const;
        order_kind get_kind()const;
        bool has_stop()const;
        const instrument & get_instrument()const;
        const execution_aggregated & get_executions()const;
        void on_event(order_status new_order_status);
        price get_stop()const;
        price get_limit()const;
        tp get_creation_time()const;

        qty qty_left()const;
        qty qty_overexec()const;

    protected:
        tp m_creation_time;
        order_status m_status = created;
        qty m_qty=0;
        order_side m_side;
        price m_limit_price = null_price;
        price m_stop_price = null_price;
        order_kind m_kind=order_kind::limit;
        const instrument & m_instrument;
        execution_aggregated  m_execs;

    };
}

#endif // TEPP_ORDER_H

