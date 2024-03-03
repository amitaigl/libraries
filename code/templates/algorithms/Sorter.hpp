#pragma once

#include "IComparator.hpp"

namespace AG
{

template <class T>
struct Sorter
{
    static void Swap(T& left, T& right)
    {
        T temp = left;
        left = right;
        right = temp;
    }

    // function quicksort(array, left, right)
    static void QuickSort(T* array, size_t array_size, const IComparator<T>& comparator)
    {
        if(array_size <= 1)
            return;
        // var pivotIdx, leftIdx = left, rightIdx = right
        size_t pivotIdx = array_size / 2, leftIdx = 0, rightIdx = array_size - 1;
        // while leftIdx <= pivotIdx and rightIdx >= pivotIdx
        while((leftIdx <= pivotIdx) && (rightIdx >= pivotIdx))
        {
            // while array[leftIdx] < array[pivotIdx] and leftIdx <= pivotIdx
            while((leftIdx <= pivotIdx) && (0 > comparator.Compare(array[leftIdx], array[pivotIdx])))
                // leftIdx = leftIdx + 1
                ++leftIdx;
            // while array[rightIdx] > array[pivotIdx] and rightIdx >= pivotIdx
            while((rightIdx >= pivotIdx) && (0 < comparator.Compare(array[rightIdx], array[pivotIdx])))
                // rightIdx = rightIdx - 1;
                --rightIdx;
            // swap array[leftIdx] with array[rightIdx]
            Swap(array[leftIdx], array[rightIdx]);
            // leftIdx = leftIdx + 1
            ++leftIdx;
            // rightIdx = rightIdx - 1
            --rightIdx;
            // if leftIdx - 1 == pivotIdx
            if(leftIdx - 1 == pivotIdx)
                // pivotIdx = rightIdx = rightIdx + 1
                pivotIdx = rightIdx = rightIdx + 1;
            // else if rightIdx + 1 == pivotIdx
            else if (rightIdx + 1 == pivotIdx)
                // pivotIdx = leftIdx = leftIdx - 1
                pivotIdx = leftIdx = leftIdx - 1;
        }
        // quicksort(array, left, pivotIdx - 1)
        QuickSort(array, pivotIdx - 1, comparator);
        // quicksort(array, pivotIdx + 1, right)
        QuickSort(array + pivotIdx + 1, array_size - (pivotIdx + 1), comparator);
    }

};

} // AG

// void Sort(T* array, size_t array_size, const IComparator<T>& comparator)
    // {
        // TODO
        /*
        1. create QuickSort func templated in this file or in separate file
            1.1. 

        2. for call it like this: QuickSort(array, array_size, comparator)
        */
        /*
        with aba:
        1. Sort class is unneccesary.
        2. template class with static funcs (this is not exists)
        3. create another utils file that contains swap func and another general funcs.
        4. create sorter module (sorter.hpp) 
        */
    // }