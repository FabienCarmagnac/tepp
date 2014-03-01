#include "tepp/book_entry.h"

#include <ostream>

namespace tepp
{
    std::ostream & book_entry::print(std::ostream & os)const
    {
        return (os << ts << ":" << quantity << "@" << price);
    }
}