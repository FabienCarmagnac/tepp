#ifndef TEPP_ORDER_EXECUTION_H
#define TEPP_ORDER_EXECUTION_H

#include <vector>
#include "tepp/gentypes.h"
#include "tepp/datetime.h"

namespace tepp
{

    class execution_single
    {
    public:
        execution_single(price p_price = 0, qty p_qty = 0, tp p_t = tp());
        price get_price()const;
        qty get_qty()const;
        tp get_time()const;

        bool is_valid()const;
        price get_nominal() const;



    protected:
        price m_price = null_price;
        qty m_qty = 0;
        tp m_t;
    };
}

inline std::ostream & operator << (std::ostream & os, const tepp::execution_single & es)
{
    return (os << tepp::tptostr(es.get_time()) << " : " << es.get_qty() << " @ " << es.get_price());
}
namespace tepp
{

    class execution_aggregated : public execution_single  
    {
    public:
        void add_execution(const execution_single & exec);
       
    };

    class execution_memory : public execution_aggregated
    {
    public:
        typedef std::vector<execution_single> container;
        const container & get_execs()const;

        void add_execution(const execution_single & exec);
    protected:
        container m_execs;
    };

}


#endif // TEPP_ORDER_EXECUTION_H
