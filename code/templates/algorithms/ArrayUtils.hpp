#pragma once

#include <cstddef>          // size_t
#include "IComparator.hpp"

namespace AG
{
enum LocateMode {   LOCATE_FIRST,   // the first object in the container
                    LOCATE_LAST,    // the last object in the container
                    LOCATE_ANY      // no matter
                };

//----------------------------------------------------------------------------------------------
//  Locate tries to locate an instance like obj in the array
//  Parameters:
//      obj         - the object that should be located
//      array       - the array to be searched sequencially
//      array_size  - the size of the array
//      mode        - the required location
//      index       = the index of the located instance (if found), or the index where the obj should be inserted
//  Returns a non NULL pointer to the located instance, if found, otherwise NULL

template <class T>
T* SeqLocate(const T& obj, const T* array, size_t array_size, const IComparator<T>& comparator, LocateMode mode, size_t& index, size_t start_index = 0)
{
    if(mode != LOCATE_LAST)
    {
        for(index = start_index; index < array_size; ++index)
        {
            if(!comparator(obj, array[index]))
                return &array[index];
        }
    }
    else
    {
        if(array_size)
        {
            for(index = array_size - 1; ; --index)
            {
                if(!comparator(obj, array[index]))
                    return &array[index];
                if(start_index == index)
                    break;
            }
        }
    }

    return NULL;
}

//----------------------------------------------------------------------------------------------
//  Locate tries to locate an instance like obj in the sorted_array
//  Parameters:
//      obj             - the object that should be located
//      sorted_array    - the array to be searched binary
//      array_size      - the size of the array
//      comparator      - the comparator interface
//      mode            - the required location 
//      index           = the index of the located instance (if found), or the index where the obj should be inserted
//  Returns a non NULL pointer to the located instance, if found, otherwise NULL

template <class T>
T* BinLocate(const T& obj, const T* sorted_array, size_t array_size, const IComparator<T>& comparator, LocateMode mode, size_t& index, size_t start_index = 0)
{
    TODO
}

//----------------------------------------------------------------------------------------------
//  Search tries to find an instance like obj in the array
//  Parameters:
//      obj           - the object that should be located
//      array         - the array to be searched sequencially
//      array_size    - the size of the array
//      mode          - the required location 
//  Returns a non NULL pointer to the located instance, if found, otherwise NULL
template <class T>
T* SeqSearch(const T& obj, const T* array, size_t array_size, const IComparator<T>& comparator, LocateMode mode = LOCATE_FIRST)
{
    size_t index;
    return SeqLocate(obj, array, array_size, comparator, mode, index);
}

//----------------------------------------------------------------------------------------------
//  Search tries to find an instance like obj in the sorted_array
//  Parameters:
//      obj             - the object that should be located
//      sorted_array    - the array to be searched binary
//      array_size      - the size of the array
//      comparator      - the comparator interface
//      mode            - the required location
//  Returns a non NULL pointer to the located instance, if found, otherwise NULL
template <class T>
T* BinSearch(const T& obj, const T* sorted_array, size_t array_size, const IComparator<T>& comparator, LocateMode mode = LOCATE_FIRST)
{
    size_t index;
    return BinLocate(obj, sorted_array, array_size, comparator, mode, index);
}

//----------------------------------------------------------------------------------------------
//  Get returns an instance like obj in the array
//  Parameters:
//      obj             - the object that should be located
//      sorted_array    - the array to be searched binary
//      array_size      - the size of the array
//      comparator      - the comparator interface
//      mode            - the required location
//  Returns ..................
template <class T>
T& SeqGet(const T& obj, const T* array, size_t array_size, const IComparator<T>& comparator, LocateMode mode)
{
    T* found = SeqSearch(obj, array, array_size, comparator, mode);
    if(!found)
    {
        throw();
    }
    return *found;
}

//----------------------------------------------------------------------------------------------
//  Get returns an instance like obj in the sorted_array
//  Parameters:
//      .....................
//  Returns ..................
template <class T>
T& BinGet(const T& obj, const T* sorted_array, size_t array_size, const IComparator<T>& comparator, LocateMode mode)
{
    T* found = BinSearch(obj, sorted_array, array_size, comparator, mode);
    if(!found)
    {
        throw();
    }
    return *found;
}

} // end namespace AG