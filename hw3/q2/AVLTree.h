/*
* Title : Heaps and AVL Trees
* Author : Ahmet Faruk Ulutas
* ID : 21803717
* Section : 1
* Assignment : 3
* Description : AVLTree.h
*/

#ifndef AVLTree_h
#define AVLTree_h
#include <iostream>

using namespace std;

void RotationAnalysis();

// Node struct with int tree properties
struct Node {
    int key;
    Node *leftChildPtr;
    Node *rightChildPtr;
    Node(int value) {
        key = value;
        leftChildPtr = NULL;
        rightChildPtr = NULL;
    }
};

class AVLTree {
public:
    // cons and dest
    AVLTree();
    ~AVLTree();

    // helpers
    void deleteTree(Node *root);
    Node* insertInorder(Node* subTreePtr, Node* newNodePtr);
    int getHeight();
    int getHeight(Node *root);
    Node* leftRotate(Node *root);
    Node* rightRotate(Node *root);

    // funcs
    void insert(int value); //inserts an element into the tree
    int getNumberOfRotations(); //returns the number of rotations performed so far while constructing the tree

    // variables
    Node *root;
    int numberOfRotations;
};

#endif
