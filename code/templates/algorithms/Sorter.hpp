#pragma once

#include "IComparator.hpp"
#include "Swap.hpp"

namespace AG
{

template <class T>
struct Sorter
{
    static void QuickSort(T* array, size_t array_size, const IComparator<T>& comparator)
    {
        if(array_size <= 1)
            return;

        size_t pivotIdx = array_size / 2, leftIdx = 0, rightIdx = array_size - 1;

        while((leftIdx <= pivotIdx) && (rightIdx >= pivotIdx))
        {
            while((leftIdx <= pivotIdx) && (0 > comparator.Compare(array[leftIdx], array[pivotIdx])))
                ++leftIdx;

            while((rightIdx >= pivotIdx) && (0 < comparator.Compare(array[rightIdx], array[pivotIdx])))
                --rightIdx;

            Swap(array[leftIdx], array[rightIdx]);
            ++leftIdx;
            --rightIdx;

            if(leftIdx - 1 == pivotIdx)
                pivotIdx = rightIdx = rightIdx + 1;
            else if (rightIdx + 1 == pivotIdx)
                pivotIdx = leftIdx = leftIdx - 1;
        }

        if(0 < pivotIdx)
        {
            QuickSort(array, pivotIdx, comparator);
        }

        if(array_size >= (pivotIdx + 1))
        {
            QuickSort(array + pivotIdx + 1, array_size - (pivotIdx + 1), comparator);
        }
    }

};

} // AG
