/**
  * Author : Ahmet Faruk Ulutas
  * ID: 21803717
  * Section : 1
  * Assignment : 4
  */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <cmath>
using namespace std;

// enums
enum CollisionStrategy { LINEAR, QUADRATIC, DOUBLE };
enum Location { Occupied, Empty, Deleted };

class HashTable {
public:
    // functions
    HashTable( const int tableSize, const CollisionStrategy option );
    ~HashTable();
    bool insert( const int item );
    bool remove( const int item );
    bool search( const int item, int& numProbes );
    void display();
    void analyze( int& numSuccProbes, int& numUnsuccProbes );

    // helpers
    int hash( int key, int i);
    int f( int i, int key);
    int reverse( int key);
    bool findAndDo( int item, string command, int& numSuccProbes);

private:
    // struct
    struct HashNode {
        Location location;
        int value;
    };

    // variables
    CollisionStrategy option;
    int numberOfElements;
    int tableSize;
    HashNode *hashArray;
};

#endif
