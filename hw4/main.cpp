/**
  * Author : Ahmet Faruk Ulutas
  * ID: 21803717
  * Section : 1
  * Assignment : 4
  */

#include "HashTable.h"
#include <fstream>
#include <sstream>
#include <string>

// Function that converts string entered numbers into int
int strToInt(string input) {
    int output = 0;

    stringstream ss(input);
    ss >> output;

    return output;
}

void testMethod( HashTable hash1) {
    int numProbs;
    int numSuccProbes;
    int numUnsuccProbes;
    int item;
    string operation;
    ifstream file;

    // opens the file entered as first parameter by user
    file.open("input.txt");

    // reads the operation and input, then makes the necessary changes
    while ( file >> operation >> item ) {
        if ( operation == "I" ) {
            if ( hash1.insert(item) )
                cout << item << " inserted" << endl;
            else
                cout << item << " not inserted" << endl;
        }

        if ( operation == "R" ) {
            if ( hash1.remove(item) )
                cout << item << " removed" << endl;
            else
                cout << item << " not removed" << endl;
        }

        if ( operation == "S" ) {
            if ( hash1.search(item, numProbs) )
                cout << item << " found after " << numProbs << " probes" << endl;
            else
                cout << item << " not found after " << numProbs << " probes" << endl;
        }
    }

    cout << "\nDISPLAY" << endl;
    // call the display function and the analyze function at the end
    hash1.display();

    cout << "\nANALYZE" << endl;
    hash1.analyze(numSuccProbes, numUnsuccProbes);

    // close the file
    file.close();
}

int main(int argc, char *argv[]) {
    // initialize the variables
    int tableSize = 31;

    // create hash tables for each case
    HashTable hash1(tableSize , LINEAR);
    HashTable hash2(tableSize , QUADRATIC);
    HashTable hash3(tableSize , DOUBLE);

    // LINEAR TEST
    cout << "LINEAR TEST" << endl;
    testMethod( hash1);

    cout << "\nQUADRATIC TEST" << endl;
    testMethod( hash2);

    cout << "\nDOUBLE TEST" << endl;
    testMethod( hash3);

    return 0;
}
