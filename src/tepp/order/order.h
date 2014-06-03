#ifndef TEPP_ORDER_H
#define TEPP_ORDER_H

#include <cstdint>
#include "tepp/order/execution.h"
#include "tepp/gentypes.h"
#include "tepp/instrument.h"

namespace tepp
{
    
    class execution_aggregated;
    class order;

    enum order_side : char { buyer = 0, seller = 1 };
    enum order_status : uint16_t
    {
        created = 0,
        pending_sent = 1,
        working = 2,
        part_executed = 4,
        executed = 8,
        pending_cancel = 16,
        canceled = 32,
        rejected = 64,
        deleted = 128
    };
    inline bool is_terminated(order_status e){ return 0 != (e & (executed | canceled | rejected | deleted)); }
    inline bool is_executable_on_exchange(order_status e){ return 0 != (e & (working | part_executed)); }
    inline bool is_executable(order_status e){ return 0 != (e & (pending_sent | working | part_executed | pending_cancel)); }
    inline bool is_cancelable(order_status e){ return 0 != (e & (working | part_executed)); }

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

        order(qty p_qty, order_kind p_kind, 
            order_side p_side, const instrument & p_instrument,
            price p_limit= null_price, price p_stop_price = null_price);

        bool terminated()const;
        qty get_qty() const;
        order_status get_status()const;
        order_kind get_kind()const;
        order_side get_side()const;
        bool has_stop()const;
        const instrument & get_instrument()const;
        const execution_aggregated & get_executions()const;
        void on_event(order_status new_order_status);
        void on_event(execution_single exec);
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

