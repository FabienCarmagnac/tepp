#ifndef TEPP_BUFFER_H_
#define TEPP_BUFFER_H_

#include "gentypes.h"

#include <iostream>
#include <stdexcept>


namespace tepp
{
/**
 * This class implements a cyclic buffer.
 * The size starts at 0 but the capacity (ie, max size)
 * is set at construction and cannot be changed.
 *
 * The iterator is a begin()-relative iterator.
 * The offset of the iterator is relative to the begin 
 * of the cyclic_buffer
 *
 */

template < class T > class cyclic_buffer
{
	T * m_base;
	T * m_end;

	size_t m_capacity;
	size_t m_size;

public:

	class iterator
	{
		const cyclic_buffer<T> & m_cb;
		size_t m_offset;
	public:
		iterator(const cyclic_buffer & cb, size_t offset=0)
			:m_cb(cb), m_offset(offset)
		{
		}
		~iterator() {}

		size_t get_offset()const
		{
			return m_offset;
		}

		const T & operator *()const
		{
			return m_cb.at(m_offset);
		}
		const T & at(int i)const
		{
			int final_offset=int(m_offset)+i;
			assert( (final_offset>=0 && final_offset<m_cb.size()) && "offset is on last element, cant apply relative offset !");
			return m_cb.at(final_offset);
		}
		const T & operator [](int i)const
		{
			return at(i);
		}

		iterator & operator ++ ()
		{
			assert(m_offset<m_cb.size() && "offset is on last element, cant ++ !");
			++m_offset;
			return *this;
		}
		iterator & operator -- ()
		{
			assert(m_offset>0 && "offset is zero, cant -- !");
			--m_offset;
			return *this;
		}
		bool operator != (const iterator & it)const
		{
			assert( (&(it.m_cb) == &m_cb) && "op != : comparing iterator on differents cyclic_buf");
			return it.m_offset != m_offset;
		}
		bool operator == (const iterator & it)const
		{
			assert( (it.m_cb == m_cb) && "op == : comparing iterator on differents cyclic_buf");
			return it.m_offset == m_offset;
		}
		bool operator < (const iterator & it)const
		{
			asset( (&it.m_cb == &m_cb) && "op < : comparing iterator on differents cyclic_buf");
			return m_offset<it.m_offset;
		}
		bool operator <= (const iterator & it)const
		{
			assert( (&it.m_cb == &m_cb) && "op <= : comparing iterator on differents cyclic_buf");
			return m_offset<=it.m_offset;
		}
	};

	cyclic_buffer(size_t capacity)
	{
		assert(capacity && "cyclic_buffer cant have capacity of 0");
		m_end=m_base=new T[m_capacity=capacity];
		m_size=0;
	}

	virtual ~cyclic_buffer()
	{
		delete [] m_base;
	}

	size_t size()const
	{
		return m_size;
	}
	size_t capacity()const
	{
		return m_capacity;
	}

	const T & operator [](int offset)const
	{
		return at(offset);
	}
	const T & at(size_t offset)const
	{
		assert( (offset<m_size) && "bad index for cyclic_buffer");

		const T * c = m_end-1-offset;
		if(c < m_base)
			return *(c + m_capacity);
		else
			return *c;
	}

	void add(const T & t)
	{
		(*m_end++) = t;

		if(m_end == m_base+m_capacity)
		{
			m_end=m_base;
		}

		if(m_size<m_capacity)
			m_size++;
	}

	iterator begin()
	{
		return iterator(*this, 0);
	}
	iterator end()
	{
		return iterator(*this, m_size);
	}


};
}

#endif // TEPP_BUFFER_H_
