#include "datetime.h"
#include <ctime>
#include <atomic>
#include <iostream>
#include <iomanip>
#include <time.h>

namespace tepp
{
    /*
    
    
    Date format : */

	void te_gmtime(const std::time_t * t, tm * out_tm)
	{
/*		static const int N = 1;
		static std::atomic<int> cnt = ATOMIC_VAR_INIT(N);
		while (std::atomic_fetch_sub(&cnt, 1) <= 0)
			std::atomic_fetch_add(&cnt, 1);
*/
        localtime_s(out_tm, t);
		out_tm->tm_isdst = -1;
		//std::atomic_fetch_add(&cnt, 1);

	}
    tp strtotp(const std::string & str)
    {
        if (str.size() < TimeFormat_YYYYMMDD_size)
            return tp();

        tm tm1 = { 0 };
        tm1.tm_isdst = -1;
        const char * c = str.c_str();
        size_t size = str.size();
        const char * end = str.c_str() + size;

        std::sscanf(c,"%4d%2d%2d",&tm1.tm_year,&tm1.tm_mon,&tm1.tm_mday);
        tm1.tm_year -= 1900;
        tm1.tm_mon--;

        if (size < TimeFormat_YYYYMMDD_HHMiSS_size)
            return clock_t::from_time_t(mktime(&tm1));

        std::sscanf(c += (TimeFormat_YYYYMMDD_size+1), "%2d%2d%2d", &tm1.tm_hour, &tm1.tm_min, &tm1.tm_sec);
        
        tp ret = clock_t::from_time_t(mktime(&tm1));
        if (size == TimeFormat_YYYYMMDD_HHMiSS_size)
            return ret;

        c = str.c_str() + TimeFormat_YYYYMMDD_HHMiSS_size;

        if (size >= (TimeFormat_YYYYMMDD_HHMiSS_size+2) && *c == '.')
        {
            c++;
            int millisecs(0);
            std::sscanf(c, "%d", &millisecs);
            if (millisecs == 0) 
                return ret;

            const char * cc = c;
            int leading_zeros = 0;
            while (cc < end && *cc == '0')
            {
                cc++;
                leading_zeros++;
            }
            int k = (TimeFormat_YYYYMMDD_HHMiSS_FFF_size - size - leading_zeros);
            if (k>0)
                millisecs *= std::pow(10, k);

            return ret + milliseconds_t(millisecs);

        }

        return ret;
    }

    bool is_business_day(const tp & ddate)
    {
        std::time_t t = clock_t::to_time_t(ddate);
		tm tm1;
		te_gmtime(&t, &tm1);
        return tm1.tm_wday!=0 && tm1.tm_wday!=6;

    }

    std::string tptostr(const tp & ddate)
    {
        std::time_t t = clock_t::to_time_t(ddate);
		std::tm tm1 = { 0 };
		te_gmtime(&t, & tm1);
        std::string buf;
        buf.reserve(TimeFormat_YYYYMMDD_HHMiSS_FFF_size+1);
        buf.resize(TimeFormat_YYYYMMDD_HHMiSS_FFF_size, '0');
        char * c = &buf[0];
        std::strftime(c, TimeFormat_YYYYMMDD_HHMiSS_FFF_size, "%Y%m%d_%H%M%S", &tm1);
        auto m = std::chrono::duration_cast<milliseconds_t>(ddate.time_since_epoch()).count();
        int millis = m % 1000;
        if (millis == 0)
        {
            buf.resize(TimeFormat_YYYYMMDD_HHMiSS_size);
            return buf;
        }

        c += TimeFormat_YYYYMMDD_HHMiSS_size;
        *c = '.';
        c++;
        if (millis < 100) c++; // leading zero
        if (millis < 10) c++;
        sprintf(c, "%d", millis);
        //microsecondes_t millisecs(ddate);
        return buf;
    }


    // return only the day part
    tp to_day(const tp & ddate)
    {
        std::time_t t = clock_t::to_time_t(ddate);
        tm tm1;
		te_gmtime(&t, &tm1);
		tm1.tm_hour = tm1.tm_min = tm1.tm_sec = 0;
        return clock_t::from_time_t(mktime(&tm1));
    }

	tp trunked_now()
	{
        std::time_t t = clock_t::to_time_t(clock_t::now());
		tm tm1;
		te_gmtime(&t, &tm1);
        return clock_t::from_time_t(mktime(&tm1));
	}
	tp now()
	{
		return clock_t::now();
	}
	std::string now_str()
    {
        return tptostr(clock_t::now());
    }
}

std::ostream & operator << (std::ostream & os, const tepp::tp & t)
{
    return (os << tepp::tptostr(t));
}
