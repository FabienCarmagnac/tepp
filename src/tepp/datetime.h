#ifndef TEPP_DATETIME_H
#define TEPP_DATETIME_H

#include <chrono>
#include <string>

#include "gentypes.h"

namespace tepp
{
    tp          strtotp(const std::string & str);
    std::string tptostr(const tp & ddate);
    tp          to_day(const tp & ddate);
    tp          trunked_now();
    bool        is_business_day(const tp & tpp);
    tp          now();
    std::string now_str();
}

std::ostream & operator << (std::ostream & os, const tepp::tp &);

#endif // TEPP_DATETIME_H
