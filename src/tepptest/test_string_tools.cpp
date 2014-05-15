#include "tepptest/helpers.h"
#include "tepp/string_tools.h"

void test_string_tools()
{


    CHECK_EQUAL(tepp::trim(" abc "), "abc");
    CHECK_EQUAL(tepp::trim(" abc\n"), "abc");
    CHECK_TRUE(tepp::trim("").empty());


    tepp::vec_str v;
    tepp::split("a ; b;  ;c ", ';', v, true);
    CHECK_EQUAL(v.at(0), "a");
    CHECK_EQUAL(v.at(1), "b");
    CHECK_EQUAL(v.at(2), "c");
    CHECK_EQUAL(v.size(), 3);
    v.clear();
    // split 

    tepp::split("; ", ';', v, false);
    CHECK_TRUE(v.at(0).empty());
    CHECK_TRUE(v.at(1).empty());
    CHECK_EQUAL(v.size(), 2);
    v.clear();

    tepp::split("", ';', v, false);
    CHECK_TRUE(v.at(0).empty());
    CHECK_EQUAL(v.size(), 1);

}
