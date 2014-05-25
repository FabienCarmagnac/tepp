#ifndef TEPP_ORDER_EXECUTION_H
#define TEPP_ORDER_EXECUTION_H

#include <vector>
#include "tepp/gentypes.h"

namespace tepp
{
    
    class execution_single
    {
    public:
        price exec_price = null_price;
        qty exec_qty = 0;
        tp exec_time;

        price get_nominal() const;
    };

    class execution_aggregated : public execution_single  
    {
    public:
        void add_execution(const execution_single & exec);
       
    };

    class execution_memory : public execution_aggregated
    {
    public:
        typedef std::vector<execution_single> container;
        container m_execs;

        const container & get_execs()const;

        void add_execution(const execution_single & exec);
    };



}


#endif // TEPP_ORDER_EXECUTION_H
