#include "tepp/order/execution.h"

#include "tepp/datetime.h"

namespace tepp
{
    execution_single::execution_single(price p_price, qty p_qty, tp p_t)
        : m_price(p_price), m_qty(p_qty), m_t(p_t)
    {}
    price execution_single::get_price()const{ return m_price; }
    qty execution_single::get_qty()const{ return m_qty; }
    tp execution_single::get_time()const{ return m_t; }


    price execution_single::get_nominal() const 
    { 
        return m_qty * m_price; 
    }  
    bool execution_single::is_valid()const
    {
        return !is_null_price(m_price);
    }
    /*std::ostream & execution_single::operator << (std::ostream & os)const
    {
        return (os << tptostr(get_time()) << " : " << get_qty() << " @ " << get_price());
    }*/
   /* std::ostream & operator << (std::ostream & os, const tepp::execution_single & es)
    {
        return (os << tptostr(es.get_time()) << " : " << es.get_qty() << " @ " << es.get_price());
    }*/
    void execution_aggregated::add_execution(const execution_single & exec)
    {
        qty new_qty = m_qty + exec.get_qty();
        m_price = (get_nominal() + exec.get_nominal()) / new_qty;
        m_qty = new_qty;
        m_t = exec.get_time();
    }
    

    



    const execution_memory::container & execution_memory::get_execs()const
    {
        return m_execs; 
    }
    void execution_memory::add_execution(const execution_single & exec)
    {
        m_execs.emplace_back(exec);
        execution_aggregated::add_execution(exec);
    }
}

