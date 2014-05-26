#include "tepp/order/execution.h"

namespace tepp
{
    price execution_single::get_nominal()const{ return exec_price * exec_qty; }

    void execution_aggregated::add_execution(const single_execution & exec)
	{
		exec_price = (get_nominal() + exec.get_nominal()) / (exec_qty + exec.exec_qty);
        exec_qty += exec.exec_qty;
        exec_time = exec.exec_time;
	}
    const execution_memory::container & executions::get_execs()const{ return m_execs; }

    void execution_memory::add_execution(execution_single && exec)
    {
        m_execs.emplace_back(exec);
		execution_aggregated::add_execution(exec);
	}
	
}

