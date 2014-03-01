#ifndef TE_ENV
#define TE_ENV

#include "tepp/import_export.h"
#include <string>


namespace tepp
{
    // change this if you want to change the way to get the root path of te env
#define TE_ENV_VAR "TE_HOME"

    /// Throw error if not found
    TE_API std::string TE_DECL root();

    /// Resolve a path containing a TE_ENV_VAR flag
    TE_API std::string TE_DECL resolve_path(const std::string & s);

    TE_API size_t TE_DECL get_nb_cores();

}

#endif // TE_ENV
