#ifndef TEPP_ORDER_H
#define TEPP_ORDER_H

#include <cstdint>
#include "tepp/gentypes.h"
#include "tepp/order/execution.h"
#include "tepp/instrument.h"

namespace tepp
{
    enum order_side : char { buyer=0, seller=1, enum_count=2 };
    enum order_status : char { created = 0, working = 1, part_executed = 2, executed = 4, canceled = 8, , rejected = 16, deleted = 32 };
    enum order_kind : char { market=0, limit =1, stop=2, stop_limit=3, enum_count=4 }; // stop_limit == stop | limit

    template < class order_owner_t > class class order
    {

    public:

        order(qty p_qty, order_kind p_kind, order_side p_side, tp p_creation_time, const instrument & p_instrument, order_owner_t  & p_owner);

        bool terminated()const { return 0 != (m_kind & (executed | canceled | rejected | deleted)); }
        qty get_qty() const{ return m_qty; }
        status get_status()const{ return m_status; }
        kind get_kind()const{ return m_kind; }
        bool has_stop()const{}
        const instrument & get_instrument()const{ return m_instrument; }
        const owner_t & get_owner()const{ return m_owner; }
        const executions & get_executions(){ return m_execs; }
        price get_stop()const{ return m_stop_price; }
        price get_limit()const{ return m_limit_price; }
        tp get_creation_time()const{ return m_creation_time; }

        qty qty_left()const
        {
            int32_t r = int32_t(get_executions().aggregated_execution().exec_qty) - m_qty;
            if (r < 0)
                return 0;
            else
                return r;
        }

        qty qty_overexec()const
        {
            int32_t r = int32_t(get_executions().aggregated_execution().exec_qty) - m_qty;
            if (r < 0)
                return -r;
            else
                return 0;
        }



    protected:
        tp m_creation_time;
        order_tatus m_status = created;
        qty m_qty=0;
        order_side m_side;
        price m_limit_price = null_price;
        price m_stop_price;
        side m_side;
        kind m_kind;
        const instrument_t & m_intrument;
        order_owner_t & m_owner;
        executions m_execs;
        const instrument & m_instrument;

    };
}

#endif // TEPP_ORDER_H

