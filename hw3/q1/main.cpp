/*
* Title : Heaps and AVL Trees
* Author : Ahmet Faruk Ulutaþ
* ID : 21803717
* Section : 1
* Assignment : 3
* Description : main.cpp
*/

#include "MedianHeap.h"
#include "MaxHeap.h"
#include "MinHeap.h"

#include <iostream>
using namespace std;

int main() {
    MaxHeap* maxHeap = new MaxHeap();
    MinHeap* minHeap = new MinHeap();
    MedianHeap* medianHeap = new MedianHeap();

    cout << "TEST FOR MAX HEAP" << endl;
    cout << "Sorted version of inserted elements: 15, 30, 45, 50, 55, 60" << endl;
    maxHeap->insert( 15);
    maxHeap->insert( 50);
    maxHeap->insert( 45);
    maxHeap->insert( 30);
    maxHeap->insert( 60); // max
    maxHeap->insert( 55); // max after extract

    cout << "size: " << maxHeap->size() << endl;
    cout << "Peek: " << maxHeap->peek() << endl;
    cout << "Extract Max: " << maxHeap->extractMax() << endl;
    cout << "size: " << maxHeap->size() << endl;
    cout << "Peek: " << maxHeap->peek() << endl;

    cout << "TEST FOR MIN HEAP" << endl;
    cout << "Sorted version of inserted elements: 15, 30, 45, 50, 55, 60" << endl;
    minHeap->insert( 15);
    minHeap->insert( 50);
    minHeap->insert( 45);
    minHeap->insert( 30);
    minHeap->insert( 60); // max
    minHeap->insert( 55); // max after extract

    cout << "size: " << minHeap->size() << endl;
    cout << "Peek: " << minHeap->peek() << endl;
    cout << "Extract Min: " << minHeap->extractMin() << endl;
    cout << "size: " << minHeap->size() << endl;
    cout << "Peek: " << minHeap->peek() << endl;

    cout << "TEST FOR MEDIAN HEAP" << endl;
    cout << "Sorted version of inserted elements: 15, 30, 45, 50, 55\nCase odd:" << endl;

    medianHeap->insert( 15);
    medianHeap->insert( 50);
    medianHeap->insert( 45);
    medianHeap->insert( 30);
    medianHeap->insert( 55); // max after extract

    cout << "Median value:" << medianHeap->findMedian() << endl;

    medianHeap->insert( 60);
    cout << "Sorted version of inserted elements: 15, 30, 45, 50, 55, 60\nCase even:" << endl;
    cout << "Median value:" << medianHeap->findMedian() << endl;
}
