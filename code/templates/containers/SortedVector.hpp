#pragma once

#include <cstddef>                                          // size_t
#include "../../../code/templates/containers/Vector.hpp"
#include "../algorithms/IComparator.hpp"
#include "../algorithms/ArrayUtils.hpp"

namespace AG
{
template <class T>
class SortedVector : public Vector<T>
{
public:
    SortedVector(const IComparator<T>& comparator, size_t capacity = 10) : Vector<T>(capacity), m_comparator(comparator) {}
    SortedVector(const SortedVector<T>& other) : Vector<T>(other), m_comparator(other.m_compare_func) {}
    SortedVector<T>& operator=(const SortedVector<T>& other)
    {
        // m_array = other.m_array; // why not works?
        *this = Vector<T>(other);
        m_comparator = other.m_comparator;
        return *this;
    }
    // virtual ~SortedVector() {}


    virtual void Add(T& obj)
    {
        obj;
        // TODO and use obj
        //GetIndex()
    }
    

private:
    const IComparator<T>& m_comparator; // 1. what if the user switches the order of arguments (new_data is first)?

    size_t GetIndex(const T& obj)
    {
        
        /*for(size_t idx = GetSize() / 2; idx; idx /= 2)
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
        }*/
    }


    void Insert(size_t position, T& obj)
    {
        position;
        obj;
        throw("Insert func is not possible"); // TODO: maybe to delete this line?
    }

};

} // AG
