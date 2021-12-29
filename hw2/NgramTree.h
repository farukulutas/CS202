/**
*  Title: Trees
*  Author: Ahmet Faruk Ulutas
*  ID: 21803717
*  Assignment: 2
*  Description: Header file of Ngramtree
*/

#ifndef NgramTree_h
#define NgramTree_h

#include "Node.h"

#include <iostream>
#include <stdio.h>
#include <fstream>

// NgramTree.h

class NgramTree {
public:
    NgramTree();
    ~NgramTree();

    void addNgram( string ngram );
    int  getTotalNgramCount();
    bool isComplete();
    bool isFull();
    void generateTree( string fileName, int n );

private:
    // instance variables
    Node *rootPtr;
    int numberOfNodes;

    bool add( string newData);
    Node* insertInorder(Node* subTreePtr, Node* newNodePtr);
    Node* findNode(Node* subTreePtr, string target);

    void getTotalNgramCountHelper( int &sum, Node* root);
    bool isCompleteHelper(Node* root ,int index);
    bool isFullHelper(Node* root);
    void inorder(Node* node, ostream& out);

    friend ostream& operator<<( ostream& out, NgramTree tree );
};

#endif
