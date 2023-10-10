/**
 *Implemention of selected sorting algorithms
 *@file sorting.cpp
 */
#include "sorting.h"

#define SHOULD_SWAP(a, b, reversed) ((!reversed && a > b) || (reversed && a < b))
#define SHOULD_SWAP_PART(a, b, reversed) ((!reversed && a < b) || (reversed && a > b))

/**
 *Implement the insertionSort algorithm correctly
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed)
{
    for (int i = lowindex + 1; i <= highindex; i++) {
        const int key = array[i];
        int j = i - 1;

        for (; j >= lowindex && SHOULD_SWAP(array[j], key, reversed); j--)
            array[j + 1] = array[j];
        array[j + 1] = key;
    }
}

static inline void swap(int& a, int& b)
{
    int temp = a;

    a = b;
    b = temp;
}

/**
 *@brief Implementation of the partition function used by quick sort
 *
 */
int partition(int array[], int lowindex, int highindex, bool reversed)
{
    const int pivot = array[highindex];
    int i = lowindex - 1;

    for (int j = lowindex; j <= highindex - 1; j++)
        if (SHOULD_SWAP_PART(array[j], pivot, reversed)) {
            i++;
            swap(array[i], array[j]);
        }
    swap(array[i + 1], array[highindex]);
    return (i + 1);
}

/**
 *Implement the quickSort algorithm correctly
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed)
{
    if (lowindex < highindex) {
        int pivotIndex = partition(array, lowindex, highindex, reversed);

        quickSort(array, lowindex, pivotIndex - 1, reversed);
        quickSort(array, pivotIndex + 1, highindex, reversed);
    }
}
