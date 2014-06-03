#ifndef TEPP_BOOK_H
#define TEPP_BOOK_H

#include <string>
#include <iostream>
#include <fstream>
#include <functional>

#include "tepp/gentypes.h"
#include "tepp/book_entry.h"

namespace tepp
{
   
    class data_level1
    {
        book_entry bid, ask, last;
    public:
        
        data_level1(const book_entry & bid, const book_entry & ask, const book_entry & last);
        data_level1(const book_entry & bid, const book_entry & ask);
        bool has_last()const{ return last.ts >= bid.ts && last.ts >= ask.ts; }
        const book_entry & get_ask() const{ return ask; }
        const book_entry & get_bid() const{ return bid; }
        const book_entry & get_last() const{ return last; }
    };

    // accumulate quantity for same price and same timestamp
    template < class base_fetcher > class fetcher_by_time
    {
        book_entry m_b;
        base_fetcher * m_base_fetcher;
        const book_entry * m_last=nullptr;
    public:
        fetcher_by_time(base_fetcher * p_base_fetcher)
            : m_base_fetcher(m_base_fetcher)
        {}

        const book_entry * fetch_next()
        {
            if (m_last==nullptr)
                m_last = m_base_fetcher->fetch_next();

            if (m_last == nullptr)
                return nullptr;

            m_b = *m_last;

            while (
                (m_last = m_base_fetcher->fetch_next()) != nullptr
                && m_last->ts == m_b.ts
                && m_last->price == m_b.price
                )
                m_b.quantity += m_last->quantity;

            return &m_b;
        }

    };
 }//ns



#endif // TEPP_BOOK_H


