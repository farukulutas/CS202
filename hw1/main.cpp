/*
 * Title: Algorithm Efficiency and Sorting
 * Author: Ahmet Faruk Ulutas
 * ID: 21803717
 * Section: 1
 * Assignment: 1
 * Description: Main file for the sorting algorithms + performance analysis
 */

#include "sorting.h"

#include <iostream>
using namespace std;


int main() {
    const int size = 16;

    // Creates 4 identical arrays of the following numbers:
    int* arr1 = new int[16]{7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int* arr2 = new int[16]{7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int* arr3 = new int[16]{7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int* arr4 = new int[16]{7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};

    // Calls the insertionSort method and the printArray() method
    int compCount = 0;
    int moveCount = 0;
    insertionSort(arr1, size, compCount, moveCount);
    printArray(arr1, size);

    // Calls the mergeSort method and the printArray() method
    compCount = 0;
    moveCount = 0;
    mergeSort(arr2, size, compCount, moveCount);
    printArray(arr2, size);

    // Calls the quickSort method and the printArray() method
    compCount = 0;
    moveCount = 0;
    quickSort(arr3, size, compCount, moveCount);
    printArray(arr3, size);

    // Calls the radixSort method and the printArray() method
    radixSort(arr4, size);
    printArray(arr4, size);

    // Calls the performanceAnalysis() method
    performanceAnalysis();

    return 0;
}
