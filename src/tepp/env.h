#ifndef TEPP_ENV
#define TEPP_ENV

#include <string>
#include <cstdlib>

namespace tepp
{
    // change this if you want to change the way to get the root path of te env
#define TEPP_ENV_VAR "TEPP_HOME"

	/// Empty string to be used to avoid copying empty strings
	const std::string & empty_string();
	
    /// Throw error if not found
    const std::string & root();

    /// Resolve a path containing a TE_ENV_VAR flag
    std::string resolve_path(const std::string & s);

    size_t get_nb_cores();

}

#endif // TEPP_ENV
