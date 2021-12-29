/*
* Title : Heaps and AVL Trees
* Author : Ahmet Faruk Ulutaþ
* ID : 21803717
* Section : 1
* Assignment : 3
* Description : MedianHeap.cpp
*/

#include "MedianHeap.h"

MedianHeap::MedianHeap(){
    size = 0;
    first = MaxHeap();
    second = MinHeap();
}

void MedianHeap::insert(int value ) {
    if( (first.size() <= 0) || (value < first.peek())){
        first.insert(value);
        rebalance();
        size++;
    } else {
        second.insert(value);
        rebalance();
        size++;
    }
}

int MedianHeap::findMedian(){
    if (size % 2 == 0) {
        if (first.peek() > second.peek()) {
            return first.peek();
        } else {
            return second.peek();
        }
    } else {
        if (first.size() > second.size()) {
            return first.peek();
        } else {
            return second.peek();
        }
    }
}

void MedianHeap::rebalance(){
    if (first.size() > second.size() + 1) {
        second.insert(first.extractMax());
    } else if (second.size() > first.size() + 1) {
        first.insert(second.extractMin());
    }
}
