#include "tepp/order/execution.h"

namespace tepp
{
    price single_execution::get_nominal()const{ return exec_price * exec_qty; }

    const single_execution & executions::aggregated_execution()const{ return m_aggreg_exec; }
    const executions::container & executions::get_execs()const{ return m_execs; }

    void executions::add_execution(single_execution && exec)
    {
        m_execs.emplace_back(exec);
        m_aggreg_exec.exec_price = (m_aggreg_exec.get_nominal() + exec.get_nominal()) / (exec_qty + exec.exec_qty);
        m_aggreg_exec.exec_qty = (m_aggreg_exec.exec_qty + exec.exec_qty);
        m_aggreg_exec.exec_time = exec.exec_time;
    }


}

