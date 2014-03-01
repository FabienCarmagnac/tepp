#ifndef TE_BUFFER_H
#define TE_BUFFER_H

#include "gentypes.h"

#include <iostream>
#include <stdexcept>


namespace tepp
{


template < class data > class cyclic_buffer
{
public:

    /* iterator relative to the begining of the buffer ie if offset == 0, the iterator will always be on the first element.
    iterator is valid from [0 .. size [ indexes */
    class iterator
    {
        size_t m_offset; // position
		cyclic_buffer<data> * m_buffer;
    public:
		iterator(cyclic_buffer<data> * mq, size_t offset = 0) : m_buffer(mq)
        {
            m_offset = offset;
        }

        iterator & operator ++ ()
        {
            ++m_offset;
#ifdef _DEBUG
            if(m_offset>m_buffer->size())
                throw std::range_error("iterator : ++ , out of bounds!");
#endif
            return *this;
        }
        iterator & operator -- ()
        {
#ifdef _DEBUG
            if(m_offset==0)
                throw std::range_error("iterator : -- , out of bounds!");
#endif
            --m_offset;
            return *this;
        }
        iterator operator + (int i)const
        {

            int target=int(m_offset)+i;
#ifdef _DEBUG
			if(target < 0 || target >m_buffer->size())
                throw std::range_error("iterator : + int , out of bounds!");
#endif

            return iterator(m_buffer, size_t(target));
        }
        iterator operator - (int i)const
        {
			int target=int(m_offset)-i;
#ifdef _DEBUG            
            if(target < 0 || target >m_buffer->size())
                throw std::range_error("iterator : - int , out of bounds!");
#endif

            return iterator(m_buffer, size_t(target));
        }
        int operator - (const iterator & i) const
        {
            return int(m_offset) - int(i.m_offset);
        }
        const data & operator * () const
        {
            return m_buffer->at(m_offset);
        }
        data & operator * ()
        {
            return m_buffer->at(m_offset);
        }
        data * operator -> ()
        {
            return &(m_buffer->at(0));
        }
        const data * operator -> ()const
        {
            return &(m_buffer->at(0));
        }
        bool operator < (const iterator & mqi) const
        {
            return m_offset < mqi.m_offset;
        }
        bool operator > (const iterator & mqi) const
        {
            return m_offset > mqi.m_offset;
        }
        bool operator <= (const iterator & mqi) const
        {
            return m_offset <= mqi.m_offset;
        }
        bool operator >= (const iterator & mqi) const
        {
            return m_offset >= mqi.m_offset;
        }
        bool operator == (const iterator & mqi) const
        {
            return m_offset == mqi.m_offset;
        }

        bool operator != (const iterator & mqi) const
        {
            return m_offset != mqi.m_offset;
        }
    };

public:
    // size is size of l
    explicit cyclic_buffer(size_t size, const data2 & init_value)
    {
#ifdef _DEBUG
		if(size==0) 
			throw std::runtime_error("cyclic_buffer ctor : size cant be 0 !");
#endif
        m_size=size;
        m_begin=new data[size];           
        m_end=m_begin+size;
        m_cur = m_end;
        for (data * c = m_begin; c != m_end; *c++ = init_value);
    }
	virtual ~cyclic_buffer()
    {
        delete [] m_begin;
    }

	cyclic_buffer & operator(const data & d)
    {
		(*m_cur) = d;
		if (m_cur + 1 == m_end)
			m_cur = m_begin;
		else
			m_cur++;
        return *this;
    }

    iterator begin()
    {
        return iterator(this,0);
    }
    iterator end()
    {
        return iterator(this, m_size);
    }

    const data & at(size_t idx)const
    {
#ifdef _DEBUG
         if(idx >= size() )
            throw std::range_error("iterator : at const, out of bounds!");
#endif
		 data * e = m_cur - (idx + 1);
		 return *(e >= m_begin ? e : e + m_size);
    }
    data & at(size_t idx)
    {
#ifdef _DEBUG
         if(idx >= size() )
            throw std::range_error("iterator : at const, out of bounds!");
#endif
		 data * e = m_cur - (idx + 1);
		 return *(e >= m_begin ? e : e + m_size);
}

    const data & operator [] (size_t idx)const
    {
        return at(idx); // check done inside at
    }
    data & operator [] (size_t idx)
    {
        return at(idx); // check done inside at
    }
    size_t size()const
    {
        return m_size;
    }

    const data & operator()()const
    {
        return *m_cur;
    }
private:

    data * m_begin, *m_end, *m_cur;
    size_t m_size;

};
}

#endif // TE_BUFFER_H

