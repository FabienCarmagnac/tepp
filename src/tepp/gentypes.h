#ifndef TEPP_GENTYPES_H_
#define TEPP_GENTYPES_H_

#include <vector>
#include <string>
#include <set>
#include <list>
#include <memory>
#include <chrono>
#include <functional>
#include <assert.h>

#include "logger.h"

namespace tepp
{
	typedef std::string str;
    typedef std::set<tepp::str> set_str;
    typedef std::vector<tepp::str> vec_str;
    typedef std::chrono::system_clock::time_point tp;
    typedef long long time8b;

    template < class T > using predicate = std::function< bool(const T &) > ;
    template < class T > using modifier = std::function< void(T &) > ;
    template < class T > using action = std::function< void(const T &) > ;
    template < class T > using comparer = std::function< int(const T &, const T &) > ;
    template < class T > using void_action = std::function< void() > ;

    template < class T, class U > using transformer = std::function< U(const T &) > ;


}

#endif // TEPP_GENTYPES_H_
