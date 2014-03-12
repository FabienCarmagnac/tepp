#ifndef TEPP_STRINGTOOLS_H
#define TEPP_STRINGTOOLS_H

#include <string>
#include <vector>
#include <memory>

#include "gentypes.h"

namespace tepp
{
    void split(const str & s, char sep, vec_str & ret, bool remove_empty = false);
    std::string         trim(const str & s);


    template < class T > std::ostream & operator << (std::ostream & os, const T & t)
    {
        return t.print(os);
    }

}

#endif // TEPP_STRINGTOOLS_H
