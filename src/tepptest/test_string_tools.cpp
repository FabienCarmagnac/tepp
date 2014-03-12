#include <UnitTest++/UnitTest++.h>

#include "tepp/string_tools.h"

TEST(string_tools)
{
	
	
CHECK_EQUAL(tepp::trim(" abc "), "abc");
CHECK_EQUAL(tepp::trim(" abc\n"), "abc");
CHECK(tepp::trim("").empty());


tepp::vec_str v;
tepp::split("a ; b;  ;c ", ';', v, true);
CHECK_EQUAL(v.at(0), "a");
CHECK_EQUAL(v.at(1), "b");
CHECK_EQUAL(v.at(2), "c");
CHECK_EQUAL(v.size(), 3);
v.clear();
// split 

tepp::split("; ", ';', v, false);
CHECK(v.at(0).empty());
CHECK(v.at(1).empty());
CHECK_EQUAL(v.size(), 2);
v.clear();

tepp::split("", ';', v, false);
CHECK(v.at(0).empty());
CHECK_EQUAL(v.size(), 1);
	
}
