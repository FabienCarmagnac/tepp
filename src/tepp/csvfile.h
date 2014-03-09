#ifndef TEPP_CSVFILE_H_
#define TEPP_CSVFILE_H_

#include <string>
#include <fstream>
#include <functional>

#include "gentypes.h"

namespace tepp
{
template < class T > s_vT< T > read_csv(const std::string & filename, char sep, std::function< T(const vs&, bool& ) > f)
{
    s_vT<T> ret (new std::vector<T>() );
    std::ifstream ifs(filename.c_str());

    if(ifs)
    {
        std::string line;
        while(getline(ifs, line))
        {
            line=trim(line);
            if(line.size() && line[0] == '#')
                continue;
            s_vs tab = split(line, sep, false);

            bool valid(false);
            T t = f(*tab.get(), valid);
            if(valid)
                ret->push_back(t);
        }
    }
    return ret;
}

}

#endif // TEPP_CSVFILE_H_
