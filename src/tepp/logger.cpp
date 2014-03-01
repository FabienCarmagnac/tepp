#include "logger.h"

#include "datetime.h"

namespace tepp
{

std::ostream & log(const std::string & source, const std::string & level)
{
    std::cout << tptostr(std::chrono::system_clock::now()) << "|" << source << "|" << level;
	return std::cout;
}

}

