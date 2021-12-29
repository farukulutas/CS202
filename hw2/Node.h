/**
*  Title: Trees
*  Author: Ahmet Faruk Ulutas
*  ID: 21803717
*  Assignment: 2
*  Description: Header file of Node
*/

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <string>
using namespace std;

class Node {
private:
    // instance variables
    string item;
    int count;
    Node *leftChildPtr;
    Node *rightChildPtr;

    // default constructor
    Node();
    Node( string nodeItem);

    // NgramTree contains Nodes. It must be able to access private parts of the Nodes.
    friend class NgramTree;
};

#endif
