/**
  * Author : Ahmet Faruk Ulutas
  * ID: 21803717
  * Section : 1
  * Assignment : 4
  */

#include "HashTable.h"

int temp = 0;

// Constructor
HashTable::HashTable( const int tableSize, const CollisionStrategy option ) {
    hashArray = new HashNode[ tableSize];
    this->option = option;
    numberOfElements = 0;
    this->tableSize = tableSize;

    // initilaze all locations to empty
    for (int i = 0; i < tableSize; i++) {
        hashArray[i].location = Empty;
    }
}

// Destructor
HashTable::~HashTable() {
    delete[] hashArray;
}

// Inserts the given item (also used as the key value) into the hash table, and returns true
// if insertion is successful, and false otherwise.
bool HashTable::insert( const int item ) {
    if ( numberOfElements < tableSize ) {
        string command = "insert";
        return findAndDo( item, command, temp);
    }

    return false;
}

// Removes the given item from the hash table, and returns true if removal is successful,
// and false otherwise.
bool HashTable::remove( const int item ) {
    string command = "remove";
    return findAndDo( item, command, temp);
}

// Searches the given item in the hash table, and returns true if search is successful (i.e.,
// the item is found), and false otherwise. This function also returns the number of probes
// used during the search for this item.
bool HashTable::search( const int item, int& numProbes ) {
    string command = "search";
    return findAndDo( item, command, numProbes);
}

// Displays the contents of the hash table in the desired format.
void HashTable::display() {
    for ( int i = 0; i < tableSize; i++ ) {
        cout << i << ": ";

        // print value if occupied
        if ( hashArray[i].location == Occupied ) {
            cout << hashArray[i].value;
        }

        cout << endl;
    }
}

/* Analyzes the current hash table in terms of the average number of probes for successful and
unsuccessful searches, and returns these two values in the variables passed by reference.
For analyzing the performance for successful searches, you can use the item values currently stored
in the table for searching. For analyzing the performance of unsuccessful searches, you can initiate
a search that starts at each array location (index), and count the number of probes needed to reach
an empty location in the array for each search.
*/
void HashTable::analyze( int& numSuccProbes, int& numUnsuccProbes ) {
    int *succItems = new int[ numberOfElements];
    int *unSuccItems = new int[ tableSize];
    int j = 0;
    int randomItem = 0;
    bool isFound = false;
    string command = "analyzeSuccessful";
    int numProbes = 0;
    numSuccProbes = 0;
    numUnsuccProbes = 0;

    // get the items in the array for successful probe
    for ( int i = 0; i < tableSize; i++ ) {
        if ( hashArray[i].location == Occupied ) {
            succItems[j] = hashArray[i].value;
            j++;
        }
    }

    // create the items for unsuccessful probe
    for ( int k = 0; k < tableSize; k++ ) {
        randomItem = (rand() % (tableSize*tableSize) ) + 1;
        isFound = false;
        for ( int l = 0; l < numberOfElements; l++) {
            if ( randomItem == succItems[l] ) {
                isFound = true;
            }
        }

        if ( !isFound ) {
            unSuccItems[k] = randomItem;
        }
    }

    // test for successful ones
    for ( int i = 0; i < numberOfElements; i++ ) {
        findAndDo( succItems[i], command, numProbes);
        numSuccProbes += numProbes;
    }

    command = "analyzeUnsuccessful";

    // test for unsuccessful ones
    for ( int i = 0; i < tableSize; i++ ) {
        // if we are analyzing DOUBLE case unsuccessful probes -1
        if ( option == DOUBLE ) {
            numUnsuccProbes = -1;
            break;
        }

        findAndDo( unSuccItems[i], command, numProbes);
        numUnsuccProbes += numProbes;
    }

    cout << "Successful Probes: " << numSuccProbes << endl;
    cout << "Unsuccessful Probes: " << numUnsuccProbes << endl;
}

// hash(key) = key mod tableSize
int HashTable::hash( int key, int i) {
    return ( (key % tableSize) + f(i, key) ) % tableSize;
}

// function named f as the collision resolution strategy
int HashTable::f( int i, int key) {
    if ( option == LINEAR ) {
        return i; // f(i) = i
    }
    else if ( option == QUADRATIC) {
        return (int) pow(i, 2); // f(i) = i^2
    }
    else {
        return i * reverse(key); // f(i) = i * hash2(key); hash2(key) = reverse(key)
    }
}

// This method reverse the integer ( hash2(key) = reverse(key) )
int HashTable::reverse( int key) {
    int remainder = 0;
    int reversedNumber = 0;

    // reversing the key
    while(key != 0) {
        remainder = key % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        key = key / 10;
    }

    return reversedNumber;
}

// This method finds the index by using hash method and does desired operation in given command.
bool HashTable::findAndDo( int item, string command, int& numProbes) {
    int hashVal = 0;
    numProbes = 0;

    // traverse the tree by desired rules until the descriptive command succesful
    for ( int i = 0; i < tableSize; i++ ) {
        hashVal = hash( item, i);

        // inserts the key
        if ( command == "insert" ) {
            // item found, cannot be re-inserted, return false.
            if ( hashArray[hashVal].value == item ) {
                return false;
            }
            if ( hashArray[hashVal].location == Empty ) {
                hashArray[hashVal].value = item;
                hashArray[hashVal].location = Occupied;
                numberOfElements++;
                return true;
            }
        }

        // remove the key
        if ( command == "remove" ) {
            if ( hashArray[hashVal].value == item && hashArray[hashVal].location == Occupied ) {
                hashArray[hashVal].location = Deleted;
                numberOfElements--;
                return true;
            }
        }

        // search the key
        if ( command == "search" ) {
            numProbes++;
            if ( hashArray[hashVal].location == Occupied && hashArray[hashVal].value == item ) {
                return true;
            }
        }

        // analyze for the successful functions
        if ( command == "analyzeSuccessful" && hashArray[hashVal].location != Deleted && hashArray[hashVal].value == item ) {
            numProbes++;
            return true;
        }

        // analyze for the unsuccessful functions
        if ( command == "analyzeUnsuccessful" && ( !(hashArray[hashVal].location != Deleted && hashArray[hashVal].value == item) )) {
            numProbes++;
            return true;
        }

        // if it comes to empty space, terminate the loop
        if ( hashArray[hashVal].location == Empty ) {
            break;
        }
    }

    return false;
}
