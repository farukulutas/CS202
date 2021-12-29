/*
* Title : Heaps and AVL Trees
* Author : Ahmet Faruk Ulutas
* ID : 21803717
* Section : 1
* Assignment : 3
* Description : analysis.cpp
*/

#include "analysis.h"
#include <bits/stdc++.h>

// funcs that creates 1000-10000 variables for trees and insert them by needed conditions
void Analysis::rotationAnalysis() {
    int x;

    cout << "-----------------------------------------------" << endl;
    cout << "Array Size | Random | Ascending | Descending " << endl;
    cout << "-----------------------------------------------" << endl;

    for ( int i = 1000; i <= 10000; i+=1000 ) {
        AVLTree* tree = new AVLTree();
        AVLTree* tree2 = new AVLTree();
        AVLTree* tree3 = new AVLTree();

        // create random variables to array
        int arr[i];
        for ( int j = 0; j < i; j++ ) {
            x = rand() % 100000 + 1;
            arr[j] = x;
        }

        // insert randomly
        for ( int k = 0; k < i; k++ ) {
            tree->insert(arr[k]);
        }

        // insert asc and desc
        sort(arr, arr + i);
        for ( int l = 0; l < i; l++ ) {
            tree2->insert(arr[l]);
            tree3->insert(arr[i - 1 - l]);
        }

        // print results
        cout << i << "\t   | " << tree->getNumberOfRotations() << "    | " << tree2->getNumberOfRotations() << "\t| "
            << tree3->getNumberOfRotations() << "\n-----------------------------------------------" << endl;

        // delete trees
        tree->~AVLTree();
        tree2->~AVLTree();
        tree3->~AVLTree();
    }
}
