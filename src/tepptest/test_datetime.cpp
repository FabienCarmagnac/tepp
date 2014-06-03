#include "tepptest/helpers.h"
#include "tepp/datetime.h"
#include <sstream>
#include <initializer_list>
#include <algorithm>

using namespace tepp;

void test_datetime()
{

    std::vector<std::pair<std::string, std::string> >  ddates =
    {
        { "20010101_130152.678", "" },
        { "20010201_130152.012", "" },
        { "20010301_130152.001", "" },
        { "20010301_130152", "20010301_130152.000" },
        { "20010401_130152.0", "20010401_130152.000" },
        { "20010501_130152.1"  , "20010501_130152.100" },
        { "20010501_130152.07" , "20010501_130152.070" },
        { "20010601_130152.999", "" },
        { "20010701_130152.", "20010701_130152.000" },
        { "20010801_130152.678", "" },
        { "20010901_130152.00", "20010901_130152.000" },
        { "20011001_130152.100", "" },
        { "20011101_130152.678", "" },
        { "20011201_130152.678", "" }
    };

    for(auto ddate : ddates)
    {
        CHECK_EQUAL(
            tptostr(strtotp(ddate.first)), 
            (ddate.second.empty() ? ddate.first : ddate.second)
            );
    }

}
