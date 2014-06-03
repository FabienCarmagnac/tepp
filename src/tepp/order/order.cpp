
#include "tepp/order/order.h"
#include "tepp/instrument.h"
#include "tepp/order/execution.h"


namespace tepp
{

    order::order(qty p_qty, order_kind p_kind, order_side p_side, const instrument & p_instrument
        , price p_limit, price p_stop_price)
        : m_qty(p_qty), m_kind(p_kind), m_side(p_side), m_instrument(p_instrument)
        , m_limit_price(p_limit), m_stop_price(p_stop_price)
    {}
    order_side order::get_side()const
    {
        return m_side;
    }
    bool order::terminated()const 
    {
        return 0 != (m_kind & (executed | canceled | rejected | deleted)); 
    }
    qty order::get_qty() const
    {
        return m_qty; 
    }
    order_status order::get_status()const
    {
        return m_status; 
    }
    order_kind order::get_kind()const
    {
        return m_kind; 
    }
    bool order::has_stop()const
    {
        return 0 !=(m_kind & order_kind::stop);
    }
    const instrument & order::get_instrument()const
    {
        return m_instrument; 
    }
    const execution_aggregated & order::get_executions()const
    { 
        return m_execs; 
    }

    void order::on_event(order_status new_order_status)
    {
        m_status = new_order_status;
    }
    void order::on_event(execution_single exec)
    {

    }

    price order::get_stop()const
    { 
        return m_stop_price; 
    }
    price order::get_limit()const
    {
        return m_limit_price; 
    }
    tp order::get_creation_time()const
    {
        return m_creation_time; 
    }

    qty order::qty_left()const
    {
        int32_t r = int32_t(m_execs.get_qty()) - m_qty;
        if (r < 0)
            return 0;
        else
            return r;
    }

    qty order::qty_overexec()const
    {
        int32_t r = int32_t(m_execs.get_qty()) - m_qty;
        if (r < 0)
            return -r;
        else
            return 0;
    }



}