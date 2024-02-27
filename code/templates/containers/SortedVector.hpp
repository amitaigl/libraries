#pragma once

#include <cstddef>  // size_t
#include "../../../code/templates/containers/Vector.hpp"

namespace AG
{
template <class T>
class SortedVector : public Vector<T>
{
public:
    SortedVector(size_t capacity = 10, int (*compare)(const void* data, const void* new_data)) : Vector<T>(capacity), m_compare_func(compare) {}
    SortedVector(const SortedVector<T>& other) : Vector<T>(other), m_compare_func(other.m_compare_func) {}
    SortedVector<T>& operator=(const SortedVector<T>& other)
    {
        m_array = other.m_array;
        m_compare_func = other.m_compare_func;
        return *this;
    }
    // virtual ~SortedVector() {}


    virtual void Add(T& obj)
    {
        //GetIndex()
    }
    

private:
    int (*m_compare_func)(const void* data, const void* new_data); // what if the user switches the order of arguments (new_data is first)?

    size_t GetIndex(const T& obj)
    {
        for(size_t idx = GetSize() / 2; idx; idx /= 2)
        {
            if(0 < m_compare_func(m_array[idx], obj))
            {
                // hh
            }
            else if(0 > m_compare_func(m_array[idx], obj))
            {
                // f
            }
            else
            {
                return idx + 1;
            }
        }
    }


    void Insert(size_t position, T& obj)
    {
        throw("Insert func is not possible");
    }

};

} // AG
