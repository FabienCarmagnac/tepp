#include "tepptest/helpers.h"
#include "tepp/env.h"

#pragma warning( disable : 4996 ) 

void test_env()
{
    CHECK_TRUE(tepp::root().size());
    CHECK_EQUAL(tepp::resolve_path("$TEPP_HOME/toto"), (std::string(std::getenv(TEPP_ENV_VAR)) + "/toto"));
    CHECK_TRUE(tepp::get_nb_cores() > 0);
}
