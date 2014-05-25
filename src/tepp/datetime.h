#ifndef TEPP_DATETIME_H
#define TEPP_DATETIME_H

#include <chrono>
#include <string>
#include <tuple>

#include "gentypes.h"

namespace tepp
{
    /*  String time format :
    * based on size:
    * 
    *              8  : YYYYMMDD
    * 8+1+6     = 15  : YYYYMMDD*HHMiSS
    * 8+1+6+1+6 = 22  : YYYYMMDD*HHMiSS.FFFFFF <= precision max : microseconds
    */

    const size_t TimeFormat_YYYYMMDD_size = 8;
    const size_t TimeFormat_YYYYMMDD_HHMiSS_size = 15;
    const size_t TimeFormat_YYYYMMDD_HHMiSS_FFF_size = 19;
        

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
