/*
* Title : Heaps and AVL Trees
* Author : Ahmet Faruk Ulutaþ
* ID : 21803717
* Section : 1
* Assignment : 3
* Description : MinHeap.h
*/

#ifndef MinHeap_h
#define MinHeap_h
#include <iostream>

using namespace std;

const int MIN_HEAP = 100;

class MinHeap {
public:
    MinHeap();
    ~MinHeap();
    void insert(int value ); // inserts integer into heap
    int peek(); // returns the value of the max element
    int extractMin(); // retrieves and removes the max element
    int size(); // returns the number of elements in the heap

    void swap( int &a, int &b);
    void heapDelete(int &item);
    void heapRebuild(int root);

private:
    int sizeOf; // for tracking size of the array
    int *items;

};

#endif
