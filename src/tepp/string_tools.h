#ifndef TE_STRINGTOOLS
#define TE_STRINGTOOLS

#include "tepp/import_export.h"

#include <string>
#include <vector>
#include <memory>

#include "gentypes.h"

namespace tepp
{
    TE_API s_vT< std::string > TE_DECL split(const std::string & s, char sep, bool remove_empty = false);
    TE_API std::string         TE_DECL trim(const std::string & s);


    template < class T > std::ostream & operator << (std::ostream & os, const T & t)
    {
        return t.print(os);
    }

}

#endif // TE_STRINGTOOLS
