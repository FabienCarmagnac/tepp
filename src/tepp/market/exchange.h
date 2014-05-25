#ifndef TEPP_EXCHANGE_H
#define TEPP_EXCHANGE_H

#include<string>

#include "tepp/gentypes.h"

namespace tepp
{

    class exchange
    {
        std::string m_description;
        milliseconds_t m_transport_time;
    public:
        exchange(const std::string & p_description = "default_standard", milliseconds_t p_transport_time = milliseconds_t(250));
        const std::string & description()const;
        milliseconds_t transport_time()const;
    };

    class fast_exchange : public exchange
    {
    public:
        fast_exchange();
    };

    class slow_exchange : public exchange
    {
    public:
        slow_exchange();
    };

    

}

#endif // TEPP_EXCHANGE_H

