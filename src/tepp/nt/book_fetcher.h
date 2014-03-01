#ifndef TE_NT_BOOK_FETCHER_H
#define TE_NT_BOOK_FETCHER_H

#include "tepp/gentypes.h"
#include "tepp/book.h"

namespace tepp
{
    namespace nt
    {

        /*
        base_fetcher has to return book_entry unique by date and by price (with accumulated qty)
        */
        template <class base_fetcher> class book_fetcher
        {
            book m_last_book;
            book_entry * m_l_a = nullptr, *m_l_b = nullptr, *m_l_l = nullptr;

            base_fetcher * m_bid, *m_ask, *m_last;

            std::vector<book_entry> asks, bids, lasts;
            std::list<book> m_books;

            // store should have at least one elem
            void fill(std::vector<book_entry> & store, base_fetcher * fetcher, const book_entry *& be)
            {
                store.push_back(*be);
                while ((be = fetcher->fetch_next()) != nullptr && be->ts == store.front().ts)
                {
                    store.push_back(*be);   
                }
            }
            void fill_till(std::vector<book_entry> & store, base_fetcher * fetcher, const book_entry *& be, time8b target)
            {
                // bid : store last
                time8b last_ts = be->ts;
                while (be != nullptr && be->ts <= target)
                {
                    if (be->ts > last_ts)
                    {
                        store.resize(1);
                        store.front() = *be;
                    }
                    else
                        store.push_back(*be);
                    be = fetcher->fetch_next();
                }
            }
            void push_book_and_resolve_last(const book_entry & bid, const book_entry & ask)
            {
                if (bid.price >= ask.price)
                    throw std::runtime_error("push_book_and_resolve_last : bid >= ask ! => bid.ts=" + std::to_string(bid.ts) + ", ask.ts=" + std::to_string(ask.ts)
                    + ", bid.price=" + std::to_string(bid.price) + ", ask.price=" + std::to_string(ask.price));

                if (m_l_l && (m_l_l->ts < bid.ts || m_l_l->ts < ask.ts))
                    throw std::runtime_error("push_book_and_resolve_last : last come too late ! => bid.ts=" + std::to_string(bid.ts) + ", ask.ts=" + std::to_string(ask.ts) + ", last.ts=" + std::to_string(m_l_l->ts));

                std::function<bool()> f = [&]()
                {
                    return (m_l_l
                        && (m_l_l->ts <= bid.ts || m_l_l->ts <= ask.ts)
                        && (bid.price <= m_l_l->price && m_l_l->price <= ask->price));
                };

                if (!f())
                    m_books.push_back(book(bid, ask, m_books.back().last));
                else
                while (f())
                {
                    m_books.push_back(book(bid, ask, m_l_l));
                    inc_last();
                }
            }

            void inc_ask() { m_l_a = m_ask->fetch_next(); }
            void inc_bid() { m_l_b = m_bid->fetch_next(); }
            void inc_last(){ m_l_l = m_last->fetch_next(); }

        public:
            // last



            book_fetcher(base_fetcher * p_bid, base_fetcher* p_ask, base_fetcher* p_last)
                :m_bid(p_bid), m_ask(p_ask), m_last(p_last)
            {
            }


            /* 

            reste dans l etat:
            book.front() est le dernier book renvoyé
            il est popé en fin de call (lorsqu'au moins un autre book a été renvoyé

            les vecteurs buffer sont cleanés

            les book_entry pointent sur le premier suivant

            */
            const book * fetch_next()
            {

                if ( ! m_books.empty())
                {
                    m_last_book = m_books.front();
                    m_books.pop_front();
                    return &m_last_book;
                }
                populate();
                if (!m_books.empty())
                {
                    m_last_book = m_books.front();
                    m_books.pop_front();
                    return &m_last_book;
                }
                else 
                    return nullptr;
            }

            void populate()
            {
                if (current_ts == 0)
                {
                    inc_ask();
                    inc_bid();
                    inc_last();

                    if (m_l_a == nullptr || m_l_b == nullptr)
                        return nullptr;

                    if (m_l_a->ts > m_l_b->ts)
                    {
                        fill(asks, m_ask, m_l_a);
                        fill_till(bids, m_bid, m_l_b, ask.front().ts);
                    }
                    else if (m_l_a->ts < m_l_b->ts)
                    {
                        fill(bids, m_bid, m_l_b);
                        fill_till(asks, m_ask, m_l_a, bids.front().ts);
                    }
                    else
                    {
                        fill(asks, m_ask, m_l_a);
                        fill(bids, m_bid, m_l_b);
                    }

                    const book_entry & l_ask = asks.front();
                    const book_entry & l_bid = bids.front();

                    if (l_ask.ts == l_bid.ts)
                    {
                        solve();
                    }
                    else if (l_ask.ts > l_bid.ts)
                    {
                        for (auto be : bids)
                        {
                            push_book_and_resolve_last(be, asks.back());
                        }
                    }
                    else if (l_ask.ts < l_bid.ts)
                    {
                        for (auto be : asks)
                        {
                            push_book_and_resolve_last(bids.back(), be);
                        }
                    }
                }
                else
                {

                    if (m_l_b & m_l_a)
                    {

                        if (m_l_a->ts > m_l_b->ts) // bid plus ancien que le ask
                        {
                            push_book_and_resolve_last(*m_l_b, m_books.back().ask);
                            inc_bid();
                        }
                        else if (m_l_a->ts < m_l_b->ts)
                        {
                            push_book_and_resolve_last(m_books.front().bid, *m_l_a);
                            inc_ask();
                        }
                        else
                        {
                            fill(asks, m_ask, m_l_a);
                            fill(bids, m_bid, m_l_b);
                            solve();
                        }
                    }
                    else
                    {
                        if (!m_l_a && !m_l_b)
                        {
                            return nullptr;
                        }
                        else if (!m_l_a)
                        {
                            push_book_and_resolve_last(*m_l_b, m_books.back().ask);
                            inc_bid();
                        }
                        else if (!m_l_b)
                        {
                            push_book_and_resolve_last(m_books.front().bid, *m_l_a);
                            inc_bid();
                        }
                    }
                }

                asks.clear();
                bids.clear();
                lasts.clear();

            }
        }; // class
    } // ns nt
}// ns te

#endif // TE_NT_BOOK_FETCHER_H

