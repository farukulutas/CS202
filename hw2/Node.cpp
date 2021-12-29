/**
*  Title: Trees
*  Author: Ahmet Faruk Ulutas
*  ID: 21803717
*  Assignment: 2
*  Description: Source code of Node
*/

#include "Node.h"

// Default constructor
Node::Node() {
    item = "";
    count = 1;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}

// Constructor
Node::Node(string nodeItem) {
    item = nodeItem;
    count = 1;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}
