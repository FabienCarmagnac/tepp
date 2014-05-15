#include "datetime.h"
#include <ctime>
#include <atomic>

namespace tepp
{

	void te_gmtime(std::time_t * t, tm * out_tm)
	{
		static const int N = 1;
		static std::atomic<int> cnt = ATOMIC_VAR_INIT(N);
		while (std::atomic_fetch_sub(&cnt, 1) <= 0)
			std::atomic_fetch_add(&cnt, 1);

		tm* ret0 = std::localtime(t);
        if (!ret0)
		{
			std::atomic_fetch_add(&cnt, 1);
			throw std::range_error("bad time_t for get_time");
		}

		*out_tm=*ret0;
		out_tm->tm_isdst = -1;
		std::atomic_fetch_add(&cnt, 1);

	}
    std::chrono::system_clock::time_point strtotp(const std::string & str)
    {
        tm tm1={0};
        std::sscanf(str.c_str(),"%4d%2d%2d_%2d%2d%2d",&tm1.tm_year,&tm1.tm_mon,&tm1.tm_mday,&tm1.tm_hour,&tm1.tm_min,&tm1.tm_sec);
        tm1.tm_year -= 1900;
        tm1.tm_mon-- ;
        tm1.tm_isdst = -1;
        return std::chrono::system_clock::from_time_t(mktime(&tm1));
    }

    bool is_business_day(const tp & ddate)
    {
        std::time_t t = std::chrono::system_clock::to_time_t(ddate);
		tm tm1;
		te_gmtime(&t, &tm1);
        return tm1.tm_wday!=0 && tm1.tm_wday!=6;

    }

    std::string tptostr(const std::chrono::system_clock::time_point & ddate)
    {
        std::time_t t = std::chrono::system_clock::to_time_t(ddate);
		tm tm1 = { 0 };
		te_gmtime(&t, & tm1);
        char buf[25]={0};
        std::strftime(buf, 24, "%Y%m%d_%H%M%S", & tm1);
        return std::string(buf);
    }


    // return only the day part
    std::chrono::system_clock::time_point to_day(const tp & ddate)
    {
        std::time_t t = std::chrono::system_clock::to_time_t(ddate);
        tm tm1;
		te_gmtime(&t, &tm1);
		tm1.tm_hour = tm1.tm_min = tm1.tm_sec = 0;
        return std::chrono::system_clock::from_time_t(mktime(&tm1));
    }

	std::chrono::system_clock::time_point trunked_now()
	{
		std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		tm tm1;
		te_gmtime(&t, &tm1);
		return std::chrono::system_clock::from_time_t(mktime(&tm1));
	}
	std::chrono::system_clock::time_point now()
	{
		return std::chrono::system_clock::now();
	}
	std::string now_str()
    {
        return tptostr(std::chrono::system_clock::now());
    }
}

std::ostream & operator << (std::ostream & os, const tepp::tp & t)
{
    return (os << tepp::tptostr(t));
}
