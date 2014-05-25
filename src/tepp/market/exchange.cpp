
#include "exchange.h"

namespace tepp
{
    exchange::exchange(const std::string & p_description, milliseconds_t p_transport_time)
        : m_description(p_description)
        , m_transport_time(p_transport_time)
    {}
    const std::string & exchange::description()const
    {
        return m_description;
    }
    milliseconds_t exchange::transport_time()const
    {
        return m_transport_time;
    }

    fast_exchange::fast_exchange() :exchange("fast_exchange", milliseconds_t(50)){}
    slow_exchange::slow_exchange() : exchange("slow_exchange", milliseconds_t(500)){}
}
