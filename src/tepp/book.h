#ifndef TE_BOOK_H
#define TE_BOOK_H

#include <string>
#include <iostream>
#include <fstream>
#include <functional>

#include "tepp/gentypes.h"
#include "tepp/book_entry.h"

namespace tepp
{
   
    class book
    {
        book_entry bid, ask, last;
    public:
        
        book(const book_entry & bid, const book_entry & ask, const book_entry & last);
        book(const book_entry & bid, const book_entry & ask);
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



#endif // TE_BOOK_H


