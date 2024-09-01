#pragma once

#include <cstddef>          // size_t
#include <stdexcept>        // std::invalid_argument
#include "IComparator.hpp"
#include <stdio.h> // TODO: delete this line

namespace AG
{
enum LocateMode {   LOCATE_FIRST,   // the first object in the container
                    LOCATE_LAST,    // the last object in the container
                    LOCATE_ANY      // no matter
                };


//----------------------------------------------------------------------------------------------
//  SeqLocate tries to locate (to find) an instance like obj in the array
//  Parameters:
//      obj         - the object that should be located
//      array       - the array to be searched sequencially
//      array_size  - the size of the array
//      comparator  - the comparator interface
//      mode        - the required location
//      index       - [out-param] the index of the located instance (if found), or the index where the obj should be inserted (ie at the end)
//      start_index - the index of the start of range
//  Returns a non NULL pointer to the located instance, if found, otherwise NULL

template <class T>
const T* SeqLocate(const T& obj, const T* array, size_t array_size, const IComparator<T>& comparator, LocateMode mode, size_t& index, size_t start_index = 0)
{
    if(mode == LOCATE_LAST)
    {
        // TODO: change the traversion on the array from start_index to the and, like in "else"
        if (array_size)
        {
            for (index = array_size - 1; start_index <= index; --index)
            {
                if (0 == comparator.Compare(obj, array[index]))
                    return &array[index];

                if (0 == index)
                {
                    index = array_size;
                    break;
                }
            }
        }
    }
    else
    {
        for (index = start_index; index < array_size; ++index)
        {
            if (0 == comparator.Compare(obj, array[index]))
                return &array[index];
        }
    }

    return NULL;
}


//----------------------------------------------------------------------------------------------
//  BinLocate tries to locate (to find) an instance like obj in the **sorted_array**
//  Parameters:
//      obj          - the object that should be located
//      sorted_array - the array to be searched binary
//      array_size   - the size of the array
//      comparator   - the comparator interface
//      mode         - the required location 
//      index        - [out-param] the index of the located instance (if found), or the index where the obj should be inserted
//      start_index  - the index of the start of range
//  Returns a non NULL pointer to the located instance, if found, otherwise NULL

template <class T>
const T* BinLocate(const T& obj, const T* sorted_array, size_t array_size, const IComparator<T>& comparator, LocateMode mode, size_t& index, size_t start_index = 0)
{
    size_t left = start_index, right = array_size - 1;

    while (left <= right)
    {
        index = (left + right) / 2;
        int result = comparator.Compare(obj, sorted_array[index]);

        if (0 < result)
        {
            if (index == right)
            {
                index = right + 1;
                break;
            }

            left = index + 1;
        }
        else if (0 > result)
        {
            if (!index)
                break;

            right = index - 1;
        }
        else
        {
            if (mode == LOCATE_LAST)
            {
                while (0 == comparator.Compare(obj, sorted_array[index]))
                {
                    ++index;
                }
                --index;
            }
            return &sorted_array[index];
        }
    }

    return NULL;
}


//----------------------------------------------------------------------------------------------
//  SeqSearch tries to find (to check if exists) an instance like obj in the array
//  Parameters:
//      obj             - the object that should be searched
//      array           - the array to be searched for sequencially
//      array_size      - the size of the array
//      comparator      - the comparator interface
//      mode            - the required location 
//  Returns a non NULL pointer to the found instance, if found, otherwise NULL

template <class T>
const T* SeqSearch(const T& obj, const T* array, size_t array_size, const IComparator<T>& comparator, LocateMode mode = LOCATE_FIRST)
{
    size_t index;
    return SeqLocate(obj, array, array_size, comparator, mode, index);
}


//----------------------------------------------------------------------------------------------
//  BinSearch tries to find (to check if exists) an instance like obj in the **sorted_array**
//  Parameters:
//      obj             - the object that should be searched
//      sorted_array    - the array to be searched for binary
//      array_size      - the size of the array
//      comparator      - the comparator interface
//      mode            - the required location
//  Returns a non NULL pointer to the found instance, if found, otherwise NULL

template <class T>
const T* BinSearch(const T& obj, const T* sorted_array, size_t array_size, const IComparator<T>& comparator, LocateMode mode = LOCATE_FIRST)
{
    size_t index;
    return BinLocate(obj, sorted_array, array_size, comparator, mode, index);
}


//----------------------------------------------------------------------------------------------
//  SeqGet returns an instance like obj in the array
//  Parameters:
//      obj         - the object that should be located
//      array       - the array to be searched for sequencially
//      array_size  - the size of the array
//      comparator  - the comparator interface
//      mode        - the required location
//  Returns reference to the instance in the array, and if there is no matching instance, throws exception

template <class T>
const T& SeqGet(const T& obj, const T* array, size_t array_size, const IComparator<T>& comparator, LocateMode mode)
{
    const T* found = SeqSearch(obj, array, array_size, comparator, mode);
    if(!found)
    {
        throw(std::invalid_argument("Obj does not exist"));
    }
    return *found;
}


//----------------------------------------------------------------------------------------------
//  BinGet returns an instance like obj in the **sorted_array**
//  Parameters:
//      obj          - the object that should be located
//      sorted_array - the array to be searched for binary
//      array_size   - the size of the array
//      comparator   - the comparator interface
//      mode         - the required location
//  Returns reference to the instance in the array, and if there is no matching instance, throws exception

template <class T>
const T& BinGet(const T& obj, const T* sorted_array, size_t array_size, const IComparator<T>& comparator, LocateMode mode)
{
    const T* found = BinSearch(obj, sorted_array, array_size, comparator, mode);
    if(!found)
    {
        throw(std::invalid_argument("Obj does not exist"));
    }
    return *found;
}

} // end namespace AG