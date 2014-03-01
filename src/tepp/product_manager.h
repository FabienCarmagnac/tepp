#ifndef TE_PRODUCT_MANAGER_H
#define TE_PRODUCT_MANAGER_H

#include <vector>

#include "product.h"
#include "gentypes.h"

namespace te
{

/*
The goal is to store all products of a kind of repo.
The loading function is passed via load function and aims
at adding to a product_container the product its create.


*/
    class product_manager
    {
        typedef std::vector< std::shared_ptr<const product*> > product_container ;
         product_container m_products;
    public:

        void xml_loader(product_container &, ss * tickers=nullptr);
        void load( modify<product_container> loader);
        const product * get_first_of( predicate< const product*> )const;
        const std::vector< const product* > & get_products()const;
};


template <class iterator> void product_manager::xml_loader(product_container & pc, iterator begin, iterator end)
{
    while(begin!=end)
    {

    }
}



}

#endif // TE_PRODUCT_MANAGER_H
