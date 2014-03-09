#ifndef TEPP_BOOK_ENTRY_H
#define TEPP_BOOK_ENTRY_H

#include "tepp/gentypes.h"

namespace tepp
{
    class book_entry
    {
    public:
        double price = 0;
        size_t quantity = 0;
        time8b ts = 0;

        std::ostream & print(std::ostream & os)const;
    };

}

#endif // TEPP_BOOK_ENTRY_H

