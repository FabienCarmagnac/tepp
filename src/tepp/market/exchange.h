#ifndef TEPP_EXCHANGE_H
#define TEPP_EXCHANGE_H

#include<string>

#include "tepp/gentypes.h"

namespace tepp
{

    class exchange
    {
    public:
         std::string description = "default";
         static const std::chrono::milliseconds & transport_time(){ static auto c = std::chrono::milliseconds(250); return c; }
         static const std::chrono::milliseconds & transport_time_on_exec(){ static auto c = std::chrono::milliseconds(201); return c; }
         static const std::chrono::milliseconds & processing_time_creation_request(){ static auto c = std::chrono::milliseconds(30); return c; }
         static const std::chrono::milliseconds & processing_time_cancel_request(){ static auto c = std::chrono::milliseconds(40); return c; }
    };
  

}

#endif // TEPP_EXCHANGE_H

