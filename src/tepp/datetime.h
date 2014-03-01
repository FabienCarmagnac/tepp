#ifndef TE_DATETIME_H
#define TE_DATETIME_H

#include "tepp/import_export.h"

#include <chrono>
#include <string>

#include "gentypes.h"

namespace tepp
{
    TE_API tp          TE_DECL strtotp(const std::string & str);
    TE_API std::string TE_DECL tptostr(const tp & ddate);
    TE_API tp          TE_DECL to_day(const tp & ddate);
    TE_API tp          TE_DECL trunked_now();
    TE_API bool        TE_DECL is_business_day(const tp & tpp);
    TE_API tp          TE_DECL now();
    TE_API std::string TE_DECL now_str();
}

TE_API std::ostream & operator << (std::ostream & os, const tepp::tp &);

#endif // TE_DATETIME_H
