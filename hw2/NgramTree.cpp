/**
*  Title: Trees
*  Author: Ahmet Faruk Ulutas
*  ID: 21803717
*  Assignment: 2
*  Description: Source code of NgramTree
*/

#include "NgramTree.h"

NgramTree::NgramTree() {
    rootPtr = NULL;
    numberOfNodes = 0;
}

NgramTree::~NgramTree() {}

bool NgramTree::add( string newData) {
    Node* newNodePtr = new Node(newData);
    rootPtr = insertInorder(rootPtr, newNodePtr);
    return true ;
} // end add

Node* NgramTree::insertInorder(Node* subTreePtr, Node* newNodePtr) {
    Node* tempPtr = NULL;

    if (subTreePtr == NULL)
        return newNodePtr;
    else if ( subTreePtr->item.compare( newNodePtr->item) > 0 ) {
        tempPtr = insertInorder(subTreePtr->leftChildPtr, newNodePtr);
        subTreePtr->leftChildPtr = tempPtr;
    }
    else {
        tempPtr = insertInorder(subTreePtr->rightChildPtr, newNodePtr);
        subTreePtr->rightChildPtr = tempPtr;
    }

    return subTreePtr;
}

Node* NgramTree::findNode(Node* subTreePtr, string target) {
    if (subTreePtr == NULL)
        return NULL;
    else if ( subTreePtr->item.compare( target) == 0)
        return subTreePtr; // Found
    else if ( subTreePtr->item.compare( target) > 0)
        // Search left subtree
        return findNode(subTreePtr->leftChildPtr, target);
    else
        // Search right subtree
        return findNode(subTreePtr->rightChildPtr, target);
}

void NgramTree::addNgram( string ngram ) {
    Node* check = findNode( rootPtr, ngram);

    if ( check == NULL ) {
        add( ngram);
        numberOfNodes++;
    }
    else {
        check->count++;
    }
}

int NgramTree::getTotalNgramCount() {
    int sum = 0;
    getTotalNgramCountHelper( sum, rootPtr);
    return sum;
}

void NgramTree::getTotalNgramCountHelper( int &sum, Node* root) {
    if (root == NULL) {
        return;
    }

    getTotalNgramCountHelper(sum, root->leftChildPtr);
    sum++;
    getTotalNgramCountHelper(sum, root->rightChildPtr);
}

bool NgramTree::isComplete() {
    return isCompleteHelper( rootPtr, 0);
}

bool NgramTree::isCompleteHelper(Node* root ,int index) {
    if (root == NULL)
        return true;

    if (index >= numberOfNodes)
        return false;

    return (isCompleteHelper(root->leftChildPtr, 2 * index + 1) && isCompleteHelper(root->rightChildPtr, 2 * index + 2));
}

bool NgramTree::isFull() {
    return isFullHelper( rootPtr);
}

bool NgramTree::isFullHelper(Node* root) {
    if (root == NULL)
        return true;

    if (root->leftChildPtr == NULL && root->rightChildPtr == NULL)
        return true;

    if ((root->leftChildPtr) && (root->rightChildPtr))
        return (isFullHelper(root->leftChildPtr) && isFullHelper(root->rightChildPtr));

    return false;
}

void NgramTree::generateTree(string fileName, int n ) {
	ifstream ff;
	ff.open(fileName.c_str());
	string w;

	while (ff >> w){
		if (w.length() >= n){

			for (int i = 0; i <= w.length() - n; i++) //thisis 3
				addNgram(w.substr( i, n));//this hisi isis
		}
	}
}

void NgramTree::inorder(Node* node, ostream& out) {
    if (node == NULL)
        return;

    inorder(node->leftChildPtr, out);
    out << "\"" << node->item << "\" appears " << node->count << " time(s)\n";
    inorder(node->rightChildPtr, out);
}

ostream& operator<<( ostream& out, NgramTree tree ) {
    tree.inorder( tree.rootPtr, out);
    return out;
}
