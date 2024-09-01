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
    /*
    * Action:       Allocates a new memory allocation according to the "capacity" argument, and inits current array.
    * Complexity:   Time - O(1).
    * Exceptions:   bad_alloc.
    */
    Array(size_t capacity = 10);

    /*
    * Action:       Copies another Array into current array, using a new memory block allocation.
    * Complexity:   Time - O(n).
    * Exceptions:   bad_alloc.
    */
    Array(const Array<T>& other);

    /*
    * Action:       Copies another Array into current array, using a new memory block allocation if needed.
    * Complexity:   Time - O(n).
    * Exceptions:   bad_alloc.
    */
    Array<T>& operator=(const Array<T>& other);

    /*
    * Action:       Destroys and frees memory.
    * Complexity:   Time - O(1).
    * Exceptions:   free errors.
    */
    virtual ~Array();


    /* --------------------------------------------------------------------------------------------
    * Action:       Checks if the array is empty.
    * Return:       "true" if empty and vice versa.
    * Complexity:   Time - O(1).
    * Exceptions:   --
    */
    bool IsEmpty() const;

    /*
    * Action:       Gives the number of elements in the array.
    * Return:       The size, as a number.
    * Complexity:   Time - O(1).
    * Exceptions:   --
    */
    size_t GetSize() const;

    /*
    * Action:       Gives the number of elements that can be stored in the array's memory block.
    * Return:       The capacity, as a number.
    * Complexity:   Time - O(1).
    * Exceptions:   --
    */
    size_t GetCapacity() const;


    /* --------------------------------------------------------------------------------------------
    * Action:       Gives access to the required element when the array is const.
    * Return:       The required element.
    * Complexity:   Time - O(1).
    * Exceptions:   out_of_range.
    */
    const T& operator[](size_t position) const;

    /*
    * Action:       Gives access to the required element.
    * Return:       The required element.
    * Complexity:   Time - O(1).
    * Exceptions:   out_of_range.
    */
    T& operator[](size_t position);

    /*
    * Action:       Gives access to the required element when the array is const.
    * Return:       The required element.
    * Complexity:   Time - O(1).
    * Exceptions:   out_of_range.
    */
    const T& At(size_t position) const;

    /*
    * Action:       Gives access to the required element.
    * Return:       The required element.
    * Complexity:   Time - O(1).
    * Exceptions:   out_of_range.
    */
    T& At(size_t position);


    /* --------------------------------------------------------------------------------------------
    * Action:       Adds a new element to the end.
                    A reference to the added element is saved in the array (and not a copy).
    * Complexity:   Time - O(1).
    * Exceptions:   bad_alloc.
    */
    void Add(const T& value);

    /*
    * Action:       Inserts a new element in the required position and pushes forward the next elements.
                    A reference to the inserted element is saved in the array (and not a copy).
    * Complexity:   Time - O(n) in worst case.
    * Exceptions:   bad_alloc or out_of_range.
    */
    void Insert(size_t position, const T& value);

    /*
    * Action:       Removes the element that exist in the required position by pulling back the following elements.
    * Complexity:   Time - O(n) in worst case.
    * Exceptions:   out_of_range.
    */
    void RemoveAt(size_t position);

    /*
    * Action:       Removes the element equal to "obj" by pulling back the following elements.
    * Return:       "true" if found and removed successfully, "false" if not.
    * Complexity:   Time - O(n).
    * Exceptions:   --
    */
    bool RemoveObj(T obj);


    /* --------------------------------------------------------------------------------------------
    * Action:       Allocates a larger memory block according to the "capacity" argument.
    * Complexity:   Time - O(n) (realloc's time complexity).
    * Exceptions:   bad_alloc.
    */
    void Reserve(size_t capacity);

    /*
    * Action:       Shortens the array according to the "size" argument, forgets the other elements.
    * Complexity:   Time - O(1).
    * Exceptions:   --
    */
    void Truncate(size_t size);

    /*
    * Action:       Shrinks the array's capacity by freeing up free space.
    * Complexity:   Time - O(n) (realloc's time complexity).
    * Exceptions:   bad_alloc.
    */
    void Shrink();

    /*
    * Action:       Forgets all array's elements.
    * Complexity:   Time - O(1).
    * Exceptions:   --
    */
    void Clean();

    /*
    * Action:       Goes back to the original capacity and forgets all array's elements.
    * Complexity:   Time - O(1).
    * Exceptions:   bad_alloc.
    */
    void Reset();


    /* --------------------------------------------------------------------------------------------
    * Action:       Searches the existence of an element in the array, when the array is const.
    * Return:       A pointer to the required element, i.e. the address of the element.
    * Complexity:   Time - O(n).
    * Exceptions:   --
    */
    const T* Find(const T obj) const;

    /*
    * Action:       Searches the existence of an element in the array.
    * Return:       A pointer to the required element, i.e. the address of the element.
    * Complexity:   Time - O(n).
    * Exceptions:   --
    */
    T* Find(const T obj);

    /*
    * Action:       Checks if the element is in the array.
    * Return:       "true" if exists and vice versa.
    * Complexity:   Time - O(n).
    * Exceptions:   --
    */
    bool IsExisting(const T obj) const;

private:
    T*     m_elements;
    size_t m_initial_capacity;
    size_t m_capacity;
    size_t m_size;


    /* --------------------------------------------------------------------------------------------
    * Action:       Allocates a new memory block.
    * Return:       A pointer to the new memory block.
    * Complexity:   Time - O(1).
    * Exceptions:   bad_alloc.
    */
    T* allocation(size_t capacity);

    /*
    * Action:       Reallocates the memory block according to the "newCapacity" argument.
    * Complexity:   Time - O(n) (realloc's time complexity).
    * Exceptions:   bad_alloc.
    */
    void reallocation(size_t newCapacity);

    /*
    * Action:       Frees the memory block.
    * Complexity:   Time - O(1).
    * Exceptions:   free errors.
    */
    void release();

    /*
    * Action:       Checks if a position is valid. If not, calls to throw_out_of_range function.
    * Complexity:   Time - O(1).
    * Exceptions:   out_of_range.
    */
    void check_range(size_t position) const;

    /*
    * Action:       Throws out_of_range exception immediately.
    * Complexity:   Time - O(1).
    * Exceptions:   out_of_range.
    */
    void throw_out_of_range() const;

};










/***************************************************************************************************
****************************************************************************************************/

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
    if (m_capacity == other.m_capacity)
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
    Insert(m_size, value);
}

template <class T>
void Array<T>::Insert(size_t position, const T &value)
{
    if (position > m_size)
    {
        throw_out_of_range();
    }
    if (m_size == m_capacity)
    {
        reallocation((m_capacity < 100) ? m_capacity + 10 : static_cast<size_t>(m_capacity * 1.1));
    }
    
    memmove(&m_elements[position + 1], &m_elements[position], (m_size - position) * sizeof(T));
    *(m_elements + position) = value;
    m_size++;
}

template <class T>
void Array<T>::RemoveAt(size_t position)
{
    if (m_size <= position)
    {
        throw_out_of_range();
    }
    std::memmove(m_elements + position, m_elements + position + 1, (m_size - 1 - position) * sizeof(T));
    m_size--;
}

template <class T>
bool Array<T>::RemoveObj(T obj) // TODO: use reference instead of by value
{
    const T* to_remove = Find(obj);
    if (!to_remove)
    {
        return false;
    }
    size_t position = ((size_t)to_remove - (size_t)m_elements) / sizeof(T);
    RemoveAt(position);

    return true;
}

template <class T>
void Array<T>::Reserve(size_t newCapacity)
{
    if (m_capacity < newCapacity)
    {
        reallocation(newCapacity);
    }
}

template <class T>
void Array<T>::Truncate(size_t size)
{
    if (size < m_size)
    {
        m_size = size;
    }
}

template <class T>
void Array<T>::Shrink()
{
    if (m_size < m_capacity)
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
    if (m_capacity != m_initial_capacity)
    {
        T* temp = allocation(m_initial_capacity);

        release();

        m_elements = temp;

        m_capacity = m_initial_capacity;
    }
    Clean();
}

template <class T>
const T* Array<T>::Find(const T obj) const // TODO: use reference
{
    for (size_t i = 0; i < m_size; ++i)
    {
        if (m_elements[i] == obj)
        {
            return &m_elements[i];
        }
    }
    return NULL;
}

template <class T>
T* Array<T>::Find(const T obj) // TODO: use reference
{
    return const_cast<T*>(static_cast<const Array*>(this)->Find(obj));
}

template <class T>
bool Array<T>::IsExisting(const T obj) const
{
    return Find(obj);
}

template <class T>
T* Array<T>::allocation(size_t capacity)
{
    T* temp = (T*)malloc(capacity * sizeof(T));

    if (!temp)
    {
        throw(std::bad_alloc());
    }

    return temp;
}

template <class T>
void Array<T>::reallocation(size_t newCapacity)
{
    if (m_capacity != newCapacity)
    {
        T* temp = (T*)realloc(m_elements, newCapacity * sizeof(T));
        
        if (!temp)
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
    if (m_size <= position)
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