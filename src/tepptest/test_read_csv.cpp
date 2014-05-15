#include "tepptest/helpers.h"

#include "tepp/csvfile.h"
#include "tepp/env.h"
#include "tepp/string_tools.h"
#include "tepptest/helpers.h"

class FakePair
{
public:
    std::string a, b;
    static FakePair make(const tepp::vec_str & v, bool & valid)
    {
        FakePair f;
        if (v.size() < 2 || v[0] == "B") valid = false;
        else
        {
            valid = true;
            f.a = v.at(0);
            f.b = v.at(1);
        }
        return f;
    }

};

void test_read_csv()
{
    std::vector<FakePair> s;
    tepp::read_csv(tepp::root() + "/data/test/read.csv", ';', FakePair::make, s);

    CHECK_EQUAL(s.size(), 2);
    CHECK_EQUAL(s[0].a, "A");
    CHECK_EQUAL(s.at(0).b, "AA");
    CHECK_EQUAL(s[1].a, "C");
    CHECK_EQUAL(s.at(1).b, "CC");
}
