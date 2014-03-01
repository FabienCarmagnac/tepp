#ifndef TE_NT_FILE_FETCHER_H
#define TE_NT_FILE_FETCHER_H

#include "tepp/gentypes.h"
#include "tepp/book.h"

#include <list>

namespace tepp
{
    namespace nt
    {

        class file_fetcher
        {
            int m_prefetch_size;
            char * m_buffer = nullptr; // begin of memory
            char * m_next_read = nullptr; // next read
            char * m_end = nullptr; // end 
            FILE * m_file = nullptr;

            std::string m_current_filename;
            book_entry m_book_entry;
            time8b m_ts = 0;
            std::list<std::string> m_files;

        public:
            std::string name;
            file_fetcher(const std::string & pname, int p_prefetch_size = 5000)
                : name(pname), m_prefetch_size(p_prefetch_size)
            {
                m_end = m_next_read = m_buffer = new char[m_prefetch_size];
            }
            virtual ~file_fetcher(){ delete m_buffer; }

            void add_file(const std::string & s)
            {
                m_files.emplace_back(s);
            }

            // null whe done
            const book_entry * fetch_next()
            {
                if (m_end == m_next_read) // need loading
                {
                    while (!m_files.empty() && m_file == nullptr)
                    {
                        m_file = std::fopen((m_current_filename = m_files.front()).c_str(), "r");
                        m_files.pop_front();
                    }

                    size_t size;
                    long pos2, pos = m_file ? 0 : ftell(m_file);
                    while (m_file && !std::fread(m_end, size = (m_end - m_buffer) + m_prefetch_size, 1, m_file)) // not good any more, try next file
                    {
                        if (m_file && (size = (ftell(m_file) - pos)) > 0) // read ?
                            break;


                            
                            fclose(m_file);
                        m_file = nullptr;


                        while (!m_files.empty() && m_file == nullptr)
                        {
                            m_file = std::fopen((m_current_filename = m_files.front()).c_str(), "r");
                            m_files.pop_front();
                        }

                        if (m_file == nullptr)
                            return nullptr;
                    }
                    m_end = size + m_buffer;
                    m_next_read = m_buffer;
                }//if

                // 1 check size
                char * start_date = m_next_read;
                char * start_price = m_next_read + 16;
                if (start_price >= m_end)
                    goto reset_memory;

                char * start_qty = start_price;
                while (start_qty != m_end && *start_qty != ';')
                    ++start_qty;
                if (start_qty == m_end)
                    goto reset_memory;

                char * end_qty = start_qty;
                while (end_qty != m_end && *end_qty != '\n')
                    ++end_qty;
                if (end_qty == m_end)
                    goto reset_memory;

                // all ok, read;
                *(start_price-1) = '\0';
                *start_qty++ = '\0';
                *end_qty = 0;

                m_book_entry.ts = atoll(start_date) * 1000000 + atoll(start_date + 9);
                m_book_entry.price = atof(start_price);
                m_book_entry.quantity = atoi(start_qty);

                m_next_read = end_qty + 1;

                return &m_book_entry;

            reset_memory:
                memcpy(m_buffer, m_next_read, m_end - m_next_read);
                m_next_read = m_end;
                return fetch_next();

            }
        };



    }//ns nt
}//ns te
#endif // TE_NT_FILE_FETCHER_H

