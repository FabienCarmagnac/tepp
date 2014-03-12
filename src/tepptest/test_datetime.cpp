#include <UnitTest++/UnitTest++.h>

#include "tepp/datetime.h"

TEST(datetime)
{

	int max_iter = 1000;

	std::string ddate = "20121212_130152";
	int j = 0, i = max_iter;
	while (++j < i) 
	{
		CHECK(tepp::strtotp(ddate) < std::chrono::system_clock::now());

		CHECK_EQUAL(tepp::tptostr(tepp::strtotp(ddate)), ddate);
		tepp::tp t = tepp::trunked_now();
		CHECK_EQUAL(tepp::strtotp(tepp::tptostr(t)), t);

	}
}
