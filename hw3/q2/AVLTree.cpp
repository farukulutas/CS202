/*
* Title : Heaps and AVL Trees
* Author : Ahmet Faruk Ulutas
* ID : 21803717
* Section : 1
* Assignment : 3
* Description : AVLTree.cpp
*/

#include "AVLTree.h"

// constr
AVLTree::AVLTree() {
    root = NULL;
    numberOfRotations = 0;
}

// destr
AVLTree::~AVLTree() {
    deleteTree(root);
}

// destr helper
void AVLTree::deleteTree(Node *root) {
    // if not empty delete by using recursion
    if (root != NULL) {
        deleteTree(root->leftChildPtr);
        deleteTree(root->rightChildPtr);
        delete root;
    }
}

// insert
void AVLTree::insert(int value) {
    Node* newNodePtr = new Node(value);
    root = insertInorder(root, newNodePtr);
}

// insert helper, insert it inorder, do rotations if needed
Node* AVLTree::insertInorder(Node* subTreePtr, Node* newNodePtr) {
    Node* tempPtr = NULL;

    // inorder insertion
    if (subTreePtr == NULL)
        return newNodePtr;
    else if ( subTreePtr->key > newNodePtr->key ) {
        tempPtr = insertInorder(subTreePtr->leftChildPtr, newNodePtr);
        subTreePtr->leftChildPtr = tempPtr;
    }
    else {
        tempPtr = insertInorder(subTreePtr->rightChildPtr, newNodePtr);
        subTreePtr->rightChildPtr = tempPtr;
    }

    // get balance
    int balance = getHeight(subTreePtr->leftChildPtr) - getHeight(subTreePtr->rightChildPtr);

    // single right rotation
    if (balance > 1 && newNodePtr->key < subTreePtr->leftChildPtr->key)
        return rightRotate(subTreePtr);

    // single left rotation
    if (balance < -1 && newNodePtr->key > subTreePtr->rightChildPtr->key)
        return leftRotate(subTreePtr);

    // double left-right rotation
    if (balance > 1 && newNodePtr->key > subTreePtr->leftChildPtr->key) {
        subTreePtr->leftChildPtr = leftRotate(subTreePtr->leftChildPtr);
        return rightRotate(subTreePtr);
    }

    // double right-left rotation
    if (balance < -1 && newNodePtr->key < subTreePtr->rightChildPtr->key) {
        subTreePtr->rightChildPtr = rightRotate(subTreePtr->rightChildPtr);
        return leftRotate(subTreePtr);
    }

    // return without rotation
    return subTreePtr;
}

// return height
int AVLTree::getHeight() {
    return getHeight(root);
}

// getHeight helper return height by recursion, traverse the tree
int AVLTree::getHeight(Node *root) {
    if (root == NULL)
        return 0;
    return max(getHeight(root->leftChildPtr), getHeight(root->rightChildPtr)) + 1;
}

// right rotation
Node* AVLTree::rightRotate(Node *root) {
    // if leaf or root null and cannot rotate
    if ( root == NULL || root->leftChildPtr == NULL ) {
        return root;
    }

    // right rotations by assignments
    Node *newOne = root->leftChildPtr;
    Node *T2 = newOne->rightChildPtr;

    newOne->rightChildPtr = root;
    root->leftChildPtr = T2;
    numberOfRotations++;
    return newOne;
}

// left rotation
Node* AVLTree::leftRotate(Node *root) {
    // if leaf or root null and cannot rotate
    if ( root == NULL || root->rightChildPtr == NULL ) {
        return root;
    }

    // left rotations by assignments
    Node *newOne = root->rightChildPtr;
    Node *T2 = newOne->leftChildPtr;

    newOne->leftChildPtr = root;
    root->rightChildPtr = T2;
    numberOfRotations++;
    return newOne;
}

// return number of rotations
int AVLTree::getNumberOfRotations() {
    return numberOfRotations;
}
