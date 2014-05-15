#ifndef TEPP_SCHEDULED_TASK_H
#define TEPP_SCHEDULED_TASK_H

#include "tepp/gentypes.h"

namespace tepp
{
    class scheduled_task
    {
    public:

        typedef int32_t id;

        scheduled_task(const action0 & p_task, const id & p_identifier, const std::chrono::milliseconds & p_recurrent)
            : task(p_task), identifier(p_identifier), recurrent(p_recurrent)
        {}

        /// the stuff to exec
        action0 task;
        /// Used to identify uniquely a task
        id identifier;
        std::chrono::milliseconds recurrent;
    };
}
#endif //TEPP_SCHEDULED_TASK_H

