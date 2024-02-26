#pragma once

#include <cstddef>  // size_t
#include "../array/Array.hpp"

namespace AG
{
template <class T>
class Vector
{
public:
    Vector(size_t capacity = 10) : m_array(capacity) {}
    Vector(const Vector<T>& other) : m_array(other.m_array) {}
    Vector<T>& operator=(const Vector<T>& other)
    {
        m_array = other.m_array;
        return *this;
    }
    virtual ~Vector() {}

    bool IsEmpty() const
    {
        return m_array.IsEmpty();
    }
    size_t GetSize() const
    {
        return m_array.GetSize();
    }
    size_t GetCapacity() const
    {
        return m_array.GetCapacity();
    }

    const T& operator[](size_t position) const
    {
        return *m_array[position];
    }
    T& operator[](size_t position)
    {
        return *m_array[position];
    }
    const T& At(size_t position) const
    {
        return *m_array.At(position);
    }
    T& At(size_t position)
    {
        return *m_array.At(position);
    }

    virtual void Add(T& obj)
    {
        m_array.Add(&obj);
    }
    virtual void Insert(size_t position, T& obj)
    {
        m_array.Insert(position, &obj);
    }
    void Remove(size_t position)
    {
        m_array.Remove(position);
    }

    void Reserve(size_t capacity)
    {
        m_array.Reserve(capacity);
    }
    void Truncate(size_t size)
    {
        m_array.Truncate(size);
    }
    void Shrink()
    {
        m_array.Shrink();
    }
    void Clean()
    {
        m_array.Clean();
    }
    void Reset()
    {
        m_array.Reset();
    }

    virtual T* Find(const T& obj)
    {
        size_t size = m_array.GetSize();

        for(size_t i = 0; i < size; ++i)
        {
            if(m_array[i] == &obj)
            {
                return m_array[i];
            }
        }
        return NULL;
    }

    bool IsExists(const T& obj)
    {
        return Find(obj);
    }

protected:
    Array<T*> m_array;

};



} // AG
