/*
* Title : Heaps and AVL Trees
* Author : Ahmet Faruk Ulutaþ
* ID : 21803717
* Section : 1
* Assignment : 3
* Description : MedianHeap.h
*/

#ifndef MedianHeap_h
#define MedianHeap_h

#include "MaxHeap.h"
#include "MinHeap.h"
#include <iostream>

using namespace std;

class MedianHeap{
public:
    MedianHeap();
    void insert(int value );
    int findMedian();

private:
    MaxHeap first;
    MinHeap second;

    int size;
    void rebalance();
};

#endif
