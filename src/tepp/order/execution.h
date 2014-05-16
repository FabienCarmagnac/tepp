#ifndef TEPP_ORDER_EXECUTION_H
#define TEPP_ORDER_EXECUTION_H

#include <vector>
#include "tepp/gentypes.h"

namespace tepp
{
    
    class single_execution
    {
    public:
        price exec_price=null_price;
        qty exec_qty = 0;
        tp exec_time;

        price get_nominal(); const{ return exec_price * exe    };

    class executions
    {
        typedef std::vector<single_execution> container;
        container m_execs;

        single_execution m_aggreg_exec;
    public:

        const single_execution & aggregated_execution()const;
        const container & get_execs()const;

        void add_execution(single_execution && exec);
    };



}


#endif // TEPP_ORDER_EXECUTION_H
