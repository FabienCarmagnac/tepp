#ifndef TE_GENTYPES_H
#define TE_GENTYPES_H

#include <vector>
#include <string>
#include <set>
#include <list>
#include <memory>
#include <chrono>
#include <functional>

#include "logger.h"

namespace tepp
{
    typedef std::set<std::string> ss;
    typedef std::vector<std::string> vs;
    typedef std::shared_ptr < vs > s_vs;
    typedef std::shared_ptr < ss > s_ss;
    typedef std::chrono::system_clock::time_point tp;
    typedef long long time8b;

    template < class T > using s_vT = std::shared_ptr< std::vector< T > > ;
    template < class T > using predicate = std::function< bool(const T &) > ;
    template < class T > using modifier = std::function< void(T &) > ;
    template < class T > using action = std::function< void(const T &) > ;
    template < class T > using comparer = std::function< int(const T &, const T &) > ;
    template < class T > using void_action = std::function< void() > ;

    template < class T, class U > using transformer = std::function< U(const T &) > ;



}

#endif // TE_GENTYPES_H
