#pragma once

#include <cstddef>      // size_t
#include <cstring>      // std::memmove
#include <stdlib.h>     // malloc, realloc
#include <stdexcept>    // std::out_of_range
#include <new>          // std:bad_alloc

namespace AG
{
template <class T>
class Array
{
public:
    Array(size_t capacity = 10);
    Array(const Array<T>& other);
    Array<T>& operator=(const Array<T>& other);
    virtual ~Array();

    bool IsEmpty() const;
    size_t GetSize() const;
    size_t GetCapacity() const;

    const T& operator[](size_t position) const;
    T& operator[](size_t position);
    const T& At(size_t position) const;
    T& At(size_t position);

    void Add(const T& value);
    void Insert(size_t position, const T& value);
    void Remove(size_t position);

    void Reserve(size_t capacity);
    void Truncate(size_t size);
    void Shrink();
    void Clean();
    void Reset();

private:
    T*     m_elements;
    size_t m_initial_capacity;
    size_t m_capacity;
    size_t m_size;

    T* allocation(size_t capacity);
    void reallocation(size_t newCapacity);
    void release();
    void check_range(size_t position) const;
    void throw_out_of_range() const;

};


/****************************************************************************/

template <class T>
Array<T>::Array(size_t capacity) :  m_elements(allocation(capacity)),
                                    m_initial_capacity(capacity),
                                    m_capacity(capacity),
                                    m_size(0)
{
    // empty
}

template <class T>
Array<T>::Array(const Array<T>& other) :    m_elements(allocation(other.m_capacity)),
                                            m_initial_capacity(other.m_initial_capacity),
                                            m_capacity(other.m_capacity),
                                            m_size(other.m_size)
{
    std::memmove(m_elements, other.m_elements, other.m_size * sizeof(T));
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if(m_capacity == other.m_capacity)
    {
        std::memmove(m_elements, other.m_elements, other.m_size * sizeof(T));
    }
    else
    {
        T* temp = allocation(other.m_capacity);

        std::memmove(temp, other.m_elements, other.m_size * sizeof(T));

        release();

        m_elements = temp;
    }

    m_initial_capacity  = other.m_initial_capacity;
    m_capacity          = other.m_capacity;
    m_size              = other.m_size;

    return *this;
}

template <class T>
Array<T>::~Array()
{
    release();
}

template <class T>
bool Array<T>::IsEmpty() const
{
    return 0 == m_size;
}

template <class T>
size_t Array<T>::GetSize() const
{
    return m_size;
}

template <class T>
size_t Array<T>::GetCapacity() const
{
    return m_capacity;
}

template <class T>
const T& Array<T>::operator[](size_t position) const
{
    check_range(position);
    
    return *(m_elements + position);
}

template <class T>
T& Array<T>::operator[](size_t position)
{
    return const_cast<T&>(static_cast<const Array&>(*this)[position]);
}

template <class T>
const T& Array<T>::At(size_t position) const
{
    return this->operator[](position);
}

template <class T>
T& Array<T>::At(size_t position)
{
    return this->operator[](position);
}

template <class T>
void Array<T>::Add(const T& value)
{
    /*if(m_size == m_capacity)
    {
        reallocation((m_capacity < 100) ? m_capacity + 10 : m_capacity * 1.1);
    }
    *(m_elements + m_size) = value;
    m_size++;*/
    Insert(m_size, value);
}

template <class T>
void Array<T>::Insert(size_t position, const T &value)
{
    if(position > m_size)
    {
        throw_out_of_range();
    }
    if(m_size == m_capacity)
    {
        reallocation((m_capacity < 100) ? m_capacity + 10 : m_capacity * 1.1);
    }
    
    memmove(&m_elements[position + 1], &m_elements[position], (m_size - position) * sizeof(T));
    *(m_elements + position) = value;
    m_size++;
}

template <class T>
void Array<T>::Remove(size_t position)
{
    if(m_size <= position)
    {
        throw_out_of_range();
    }
    std::memmove(m_elements + position, m_elements + position + 1, (m_size - 1 - position) * sizeof(T));
    m_size--;
}

template <class T>
void Array<T>::Reserve(size_t newCapacity)
{
    if(m_capacity < newCapacity)
    {
        reallocation(newCapacity);
    }
}

template <class T>
void Array<T>::Truncate(size_t size)
{
    if(size < m_size)
    {
        m_size = size;
    }
}

template <class T>
void Array<T>::Shrink()
{
    if(m_size < m_capacity)
    {
        reallocation(m_size);
    }
}

template <class T>
void Array<T>::Clean()
{
    m_size = 0;
}

template <class T>
void Array<T>::Reset()
{
    if(m_capacity != m_initial_capacity)
    {
        T* temp = allocation(m_initial_capacity);

        release();

        m_elements = temp;

        m_capacity = m_initial_capacity;
    }
    Clean();
}

template <class T>
T* Array<T>::allocation(size_t capacity)
{
    T* temp = (T*)malloc(capacity * sizeof(T));

    if(!temp)
    {
        throw(std::bad_alloc());
    }

    return temp;
}

template <class T>
void Array<T>::reallocation(size_t newCapacity)
{
    if(m_capacity != newCapacity)
    {
        T* temp = (T*)realloc(m_elements, newCapacity * sizeof(T));
        
        if(!temp)
        {
            throw(std::bad_alloc());
        }

        m_elements = temp;
        m_capacity = newCapacity;
    }
}

template <class T>
void Array<T>::release()
{
    free(m_elements);
}

template <class T>
void Array<T>::check_range(size_t position) const
{
    if(m_size <= position)
    {
        throw_out_of_range();
    }
}

template <class T>
void Array<T>::throw_out_of_range() const
{
    throw(std::out_of_range("Error: out of range"));
}

} // AG