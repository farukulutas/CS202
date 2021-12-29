/*
* Title : Heaps and AVL Trees
* Author : Ahmet Faruk Ulutaþ
* ID : 21803717
* Section : 1
* Assignment : 3
* Description : MinHeap.cpp
*/

#include "MinHeap.h"

MinHeap::MinHeap() {
    sizeOf = 0;
    items = new int[MIN_HEAP];
}

MinHeap::~MinHeap() {
    if ( size() > 0 ) {
        delete [] items;
        sizeOf = 0;
    }
}

void MinHeap::insert(int value) {
    if ( size() >= MIN_HEAP) {
        cout << "Heap is full!" << endl;
        return;
    }

    int place = size();
    int parent = (place - 1) / 2;
    items[ place] = value;

    while ( (place > 0) && (items[place] < items[parent]) ) {
        swap( items[place], items[parent]);
        place = parent;
        parent = (place - 1) / 2;
    }

    ++sizeOf;
}

int MinHeap::peek() {
    if ( size() > 0 ) {
        return items[0];
    }

    return -1;
}

int MinHeap::extractMin() {
    if ( size() <= 0 ) {
        return -1;
    } else {
        int min = peek();
        heapDelete(items[0]);
        return min;
    }
}

int MinHeap::size() {
    return sizeOf;
}

void MinHeap::swap( int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void MinHeap::heapDelete(int &item){
    if ( size() <= 0 ) {
        cout << "Heap is empty!" << endl;
    } else {
        item = peek();
        items[0] = items[--sizeOf];
        heapRebuild(0);
    }
}

void MinHeap::heapRebuild(int root){
    int child = 2 * root + 1;
    if ( child < size()) {
        // not a leaf situation check existance of right child
        int rightChild = child + 1;     // index of a right child, if any
        // If root has right child, find larger child
        if ( (rightChild < size()) && (items[rightChild] < items[child]) ){
            child = rightChild;     // get the position of the largest child
        }
        // check root value swap if smaller
        if ( items[root] > items[child]) {
            swap( items[root], items[child]);

            // obtain the heap property back for child pointer
            heapRebuild(child);
        }
    }
}
