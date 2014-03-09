#include <UnitTest++/UnitTest++.h>

#include "tepp/env.h"

TEST(env)
{
	CHECK(tepp::root().size());
	CHECK_EQUAL(tepp::resolve_path("$TEPP_HOME/toto"), (std::string(std::getenv(TEPP_ENV_VAR)) + "/toto"));
	CHECK(tepp::get_nb_cores() > 0);
}
