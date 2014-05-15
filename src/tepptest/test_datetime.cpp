#include "tepptest/helpers.h"
#include "tepp/datetime.h"
#include <sstream>

void test_datetime()
{

    std::string ddate = "20010101_130152";
    CHECK_TRUE(tepp::strtotp(ddate) < std::chrono::system_clock::now());
    tepp::tp t = tepp::trunked_now();
    CHECK_EQUAL(tepp::strtotp(tepp::tptostr(t)), t);

    for(int i=1;i<=12;i++)
    {
        std::ostringstream ddate;
        ddate << "2012";
        if (i < 10) ddate << "0";
        ddate << i << "01_130152";

        CHECK_EQUAL(tepp::tptostr(tepp::strtotp(ddate.str())), ddate.str());

    }
}
