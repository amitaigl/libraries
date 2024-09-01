#pragma once

#include <cstddef>  // size_t
#include "../../../code/templates/containers/Array.hpp"

namespace AG
{
template <class T>
class Vector
{
public:
    /*
    * Action:       Allocates a new memory allocation according to the "capacity" argument, and inits current array.
    * Complexity:   Time - O(1).
    * Exceptions:   bad_alloc.
    */
    Vector(size_t capacity = 10) : m_array(capacity) {}

    /*
    * Action:       Copies another Vector into current vector, using a new memory block allocation.
    * Complexity:   Time - O(n).
    * Exceptions:   bad_alloc.
    */
    Vector(const Vector<T>& other) : m_array(other.m_array) {}

    /*
    * Action:       Copies another Vector into current vector, using a new memory block allocation if needed.
    * Complexity:   Time - O(n).
    * Exceptions:   bad_alloc.
    */
    Vector<T>& operator=(const Vector<T>& other)
    {
        m_array = other.m_array;
        return *this;
    }

    /*
    * Action:       Destroys and frees memory.
    * Complexity:   Time - O(1).
    * Exceptions:   free errors.
    */
    virtual ~Vector() {}


    /* --------------------------------------------------------------------------------------------
    * Action:       Checks if the vector is empty.
    * Return:       "true" if empty and vice versa.
    * Complexity:   Time - O(1).
    * Exceptions:   --
    */
    bool IsEmpty() const
    {
        return m_array.IsEmpty();
    }

    /*
    * Action:       Gives the number of elements in the vector.
    * Return:       The size, as a number.
    * Complexity:   Time - O(1).
    * Exceptions:   --
    */
    size_t GetSize() const
    {
        return m_array.GetSize();
    }

    /*
    * Action:       Gives the number of elements that can be stored in the vector's memory block.
    * Return:       The capacity, as a number.
    * Complexity:   Time - O(1).
    * Exceptions:   --
    */
    size_t GetCapacity() const
    {
        return m_array.GetCapacity();
    }


    /* --------------------------------------------------------------------------------------------
    * Action:       Gives access to the required element when the vector is const.
    * Return:       The required element.
    * Complexity:   Time - O(1).
    * Exceptions:   out_of_range.
    */
    const T& operator[](size_t position) const
    {
        return *m_array[position];
    }

    /*
    * Action:       Gives access to the required element.
    * Return:       The required element.
    * Complexity:   Time - O(1).
    * Exceptions:   out_of_range.
    */
    T& operator[](size_t position)
    {
        return *m_array[position];
    }

    /*
    * Action:       Gives access to the required element when the vector is const.
    * Return:       The required element.
    * Complexity:   Time - O(1).
    * Exceptions:   out_of_range.
    */
    const T& At(size_t position) const
    {
        return *m_array.At(position);
    }

    /*
    * Action:       Gives access to the required element.
    * Return:       The required element.
    * Complexity:   Time - O(1).
    * Exceptions:   out_of_range.
    */
    T& At(size_t position)
    {
        return *m_array.At(position);
    }


    /* --------------------------------------------------------------------------------------------
    * Action:       Adds a new element to the end.
                    A reference to the added element is saved in the vector (and not a copy).
    * Complexity:   Time - O(1).
    * Exceptions:   bad_alloc.
    */
    virtual void Add(T& obj)
    {
        m_array.Add(&obj);
    }

    /*
    * Action:       Inserts a new element in the required position and pushes forward the next elements.
                    A reference to the inserted element is saved in the vector (and not a copy).
    * Complexity:   Time - O(n) in worst case.
    * Exceptions:   bad_alloc or out_of_range.
    */
    virtual void Insert(size_t position, T& obj)
    {
        m_array.Insert(position, &obj);
    }

    /*
    * Action:       Removes the element that exist in the required position by pulling back the following elements.
    * Complexity:   Time - O(n) in worst case.
    * Exceptions:   out_of_range.
    */
    void Remove(size_t position)
    {
        m_array.RemoveAt(position);
    }

    /*
    * Action:       Removes the element equal to "obj" by pulling back the following elements.
    * Return:       "true" if found and removed successfully, "false" if not.
    * Complexity:   Time - O(n).
    * Exceptions:   --
    */
    bool Remove(T& obj)
    {
        return m_array.RemoveObj(&obj);
    }

    /*
    * Action:       Deletes (ie frees, deallocates) from the memory the element that equal to "obj".
    * Return:       "true" if found and deleted successfully, "false" if not.
    * Complexity:   Time - O(n).
    * Exceptions:   --
    */
    bool Delete(T& obj)
    {
        if (!Remove(obj))
        {
            return false;
        }
        delete &obj;
        return true;
    }


    /* --------------------------------------------------------------------------------------------
    * Action:       Allocates a larger memory block according to the "capacity" argument.
    * Complexity:   Time - O(n) (realloc's time complexity).
    * Exceptions:   bad_alloc.
    */
    void Reserve(size_t capacity)
    {
        m_array.Reserve(capacity);
    }

    /*
    * Action:       Shortens the vector according to the "size" argument, forgets the other elements.
    * Complexity:   Time - O(1).
    * Exceptions:   --
    */
    void Truncate(size_t size)
    {
        m_array.Truncate(size);
    }

    /*
    * Action:       Shrinks the vector's capacity by freeing up free space.
    * Complexity:   Time - O(n) (realloc's time complexity).
    * Exceptions:   bad_alloc.
    */
    void Shrink()
    {
        m_array.Shrink();
    }

    /*
    * Action:       Forgets all vector's elements.
    * Complexity:   Time - O(1).
    * Exceptions:   --
    */
    void Clean()
    {
        m_array.Clean();
    }

    /*
    * Action:       Goes back to the original capacity and forgets all vector's elements.
    * Complexity:   Time - O(1).
    * Exceptions:   bad_alloc.
    */
    void Reset()
    {
        m_array.Reset();
    }


    /* --------------------------------------------------------------------------------------------
    * Action:       Searches the existence of an element in the vector.
    * Return:       A pointer to the required element, i.e. the address of the element.
    * Complexity:   Time - O(n).
    * Exceptions:   --
    */
    const T* Find(const T& obj) const
    {
        // T* const* value = m_array.Find((T*)&obj); // TODO: after thorough testing, delete this line
        T* const* value = m_array.Find(const_cast<T*>(&obj));
        return (value) ? *value : NULL;
    }

    /*
    * Action:       Searches the existence of an element in the vector.
    * Return:       A pointer to the required element, i.e. the address of the element.
    * Complexity:   Time - O(n).
    * Exceptions:   --
    */
    T* Find(const T& obj)
    {
        return const_cast<T*>(static_cast<const Vector*>(this)->Find(obj));
    }

    /*
    * Action:       Checks if the element is in the vector.
    * Return:       "true" if exists and vice versa.
    * Complexity:   Time - O(n).
    * Exceptions:   --
    */
    bool IsExisting(const T& obj) const
    {
        return Find(obj);
    }

protected:
    /*
    * m_array is not private to provide access for wrappers like SortedVector.
    * The array elements are T* to allow different types of elements in the same array (polymorphism).
    */
    Array<T*> m_array;

};



} // AG
