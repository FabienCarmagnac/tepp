#ifndef TE_STRINGTOOLS
#define TE_STRINGTOOLS

#include <string>
#include <vector>
#include <memory>

#include "gentypes.h"

namespace tepp
{
    s_vT< std::string > split(const std::string & s, char sep, bool remove_empty = false);
    std::string         trim(const std::string & s);


    template < class T > std::ostream & operator << (std::ostream & os, const T & t)
    {
        return t.print(os);
    }

}

#endif // TE_STRINGTOOLS
