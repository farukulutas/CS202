/*
 * Title: Algorithm Efficiency and Sorting
 * Author: Ahmet Faruk Ulutas
 * ID: 21803717
 * Section: 1
 * Assignment: 1
 * Description: Source file for the sorting algorithms + performance analysis
 */

#include "sorting.h"
using namespace std;

// INSERTION SORT

void insertionSort(int *arr, int size, int &compCount, int &moveCount) {

  for (int unsorted = 1; unsorted < size; ++unsorted) {

    int nextItem = arr[unsorted];
    moveCount++;
    int loc = unsorted;

    for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc) {
       arr[loc] = arr[loc-1];
        moveCount++;
    }

    arr[loc] = nextItem;
    moveCount++;
  }
}

// MERGE SORT

void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount) {

    int tempArray[last-first+1];     // temporary array

    int first1 = first;     // beginning of first subarray
    int last1 = mid;         // end of first subarray
    int first2 = mid + 1;    // beginning of second subarray
    int last2 = last;        // end of second subarray
    int index = first1; // next available location in tempArray

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        compCount++;
        if (arr[first1] < arr[first2]) {
            moveCount++;
            tempArray[index] = arr[first1];
            ++first1;
        }
        else {
            moveCount++;
            tempArray[index] = arr[first2];
            ++first2;
        }
    }

    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index) {
        moveCount++;
        tempArray[index] = arr[first1];
    }

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        moveCount++;
        tempArray[index] = arr[first2];
    }

    // copy the result back into the original array
    for (index = first; index <= last; ++index) {
        moveCount++;
        arr[index] = tempArray[index];
    }

}

void mergesort(int *arr, int first, int last, int &compCount, int &moveCount) {

    if (first < last) {

      int mid = (first + last) / 2;     // index of midpoint

      mergesort(arr, first, mid, compCount, moveCount);

      mergesort(arr, mid+1, last, compCount, moveCount);

      // merge the two halves
      merge(arr, first, mid, last, compCount, moveCount);
   }
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    mergesort(arr, 0, size - 1, compCount, moveCount);
}

// QUICK SORT

void swap(int &a, int &b, int &compCount, int &moveCount){
    int temp = a;
    a = b;
    b = temp;
    moveCount += 3;
}

void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
   // Precondition: theArray[first..last] is an array; first <= last.
   // Postcondition: Partitions theArray[first..last] such that:
   //   S1 = theArray[first..pivotIndex-1] < pivot
   //   theArray[pivotIndex] == pivot
   //   S2 = theArray[pivotIndex+1..last] >= pivot

    // place pivot in theArray[first]
   int pivot = theArray[first]; // copy pivot
    moveCount++;

   // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

    // move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot) {      // belongs to S1
          ++lastS1;
          swap(theArray[firstUnknown], theArray[lastS1], compCount, moveCount);
      }

      compCount++;   // else belongs to S2
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1], compCount, moveCount);
   pivotIndex = lastS1;
}

void quicksorted(int *theArray, int first, int last, int &compCount, int &moveCount) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

   if (first < last) {

      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      quicksorted(theArray, first, pivotIndex-1, compCount, moveCount);
      quicksorted(theArray, pivotIndex+1, last, compCount, moveCount);
   }
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    int nonConstSize = size - 1;
    quicksorted( arr, 0, nonConstSize, compCount, moveCount);
}

// RADIX SORT


int numberOfDigits( int no){
    int digits = 0;
    if (no < 0){
        digits = 1;
    }
    while (int(no != 0)) {
        no /= 10;
        digits++;
    }
    return digits;
}

int getMax( int *arr, int size){
    int num = numberOfDigits(arr[0]);
    for (int i = 0; i < size; i++) {
        if (num < numberOfDigits(arr[i]) ) {
            num = numberOfDigits(arr[i]);
        }
    }
    return num;
}

void radixSorted( int *theArray, int n, int d) {
// sort n d-digit integers in the array theArray
    for (int j = d; j > 1; j--) {
         int array[10][n]; // 2D Array initialized to 0
         int countArray[10] = {0}; // Counter to count items in the arrays.

         for (int i = 0; i < n-1; i++) {
              int k  = ((int)(theArray[i]/pow(10, j)))%10; // last digit
              int pos = countArray[((int)(theArray[i]/pow(10, j)))%10]; // increment the number
              array[ k ][pos] = theArray[i]; // add the element to there
              countArray[(int)(theArray[i]/pow(10, j))%10] = pos+1;
         }

         int curPos = 0;
        for (int i = 0; i < 10; i++) {
            // get the element write to the array
            int cur = 0;
            while(cur < countArray[i]){
                theArray[curPos++] = array[i][cur];
                cur++;
            }
        }
    }
}

void radixSort(int *arr, int size) {
    int max = getMax(arr, size);
    radixSorted( arr, size, max);
}

void printArray(int *arr, int size){
    if (arr != NULL) {
        cout << "[";
        for(int i = 0; i < size-1; i++){
            cout << arr[i] << ", ";
        }
        cout << arr[size-1];
        cout << "]" << endl;
    } else {
        cout << "[]" << endl;
    }
}

void printHeader(string sortType){
    if (sortType == "insertionSort") {
        // print the time
        cout << "------------------------------------" << endl;
        cout << "Part a – Time Analysis of Insertion Sort" << endl;
        cout << "Array size" << setw(15) << "Time Elapsed" << endl;
    } else if (sortType == "mergeSort") {
        // print the time
        cout << "------------------------------------" << endl;
        cout << "Part b – Time Analysis of Merge Sort" << endl;
        cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    } else if (sortType == "quickSort"){
        // print the time
        cout << "------------------------------------" << endl;
        cout << "Part c – Time Analysis of Quick Sort" << endl;
        cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    } else if(sortType == "radixSort") {
        // print the time
        cout << "------------------------------------" << endl;
        cout << "Part d - Time analysis of Radix Sort" << endl;
        cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    } else {
        // invalid algorithm
        cout << "Invalid algorithm type...";
    }
}

string printPerformanceOut(int * arr, int size, string sortType){
    int compCount = 0;
    int moveCount = 0;
    string result = "";
    clock_t counter; // time elapsed
    if (sortType == "insertionSort") {
        counter = clock();
        insertionSort(arr,size,compCount,moveCount);
        counter = clock() - counter;
        double timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
        result  = to_string(size) + "           " + to_string(timeElapsed) + " ms";
    } else if (sortType == "mergeSort") {
        counter = clock();
        mergeSort(arr, size, compCount, moveCount);
        counter = clock() - counter;
        double timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
        result  = to_string(size) + "          " + to_string(timeElapsed) + " ms     " + to_string(compCount)+ "        " + to_string(moveCount);
    } else if (sortType == "quickSort"){
        counter = clock();
        quickSort(arr, size, compCount, moveCount);
        counter = clock() - counter;
        double timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
        result  = to_string(size) + "          " + to_string(timeElapsed) + " ms      " + to_string(compCount)+ "       " + to_string(moveCount);
    } else if(sortType == "radixSort") {
        counter = clock();
        radixSort(arr, size);
        counter = clock() - counter;
        double timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
        result  = to_string(size) + "            " + to_string(timeElapsed) + " ms       " + to_string(compCount)+ "         " + to_string(moveCount);
    } else {
        // invalid algorithm
        cout << "Invalid algorithm type...";
    }
    return result;
}

void createArrays(int *arr1, int *arr2, int *arr3, int *arr4, int size){
    srand((int) time(NULL)); // random seed initialization

    for (int i = 0; i < size; i++) {
        int randNum = rand() % size + 1 ; // random number taking values in between [1:size]
        arr1[i] = randNum; // reserved for radix sort
        arr2[i] = randNum; // reserved for bubble sort
        arr3[i] = randNum; // reserved for quick sort
        arr4[i] = randNum; // reserved for merge sort
    }
}

void getResult(int size, string *resArr){
    int *arr1 = new int[size];
    int *arr2 =  new int[size];
    int *arr3 =  new int[size];
    int *arr4 =  new int[size];

    createArrays(arr1, arr2, arr3, arr4, size);

    string res1 = printPerformanceOut(arr1, size, "insertionSort");
    string res2 = printPerformanceOut(arr2, size, "mergeSort");
    string res3 = printPerformanceOut(arr3, size, "quickSort");
    string res4 = printPerformanceOut(arr4,size, "radixSort");

    resArr[0] = res1;
    resArr[1] = res2;
    resArr[2] = res3;
    resArr[3] = res4;

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
}

void performanceAnalysis(){
    int arraySizes[8] = {2000, 6000, 10000, 14000, 18000, 22000, 26000, 30000};
    string resultArray[8][4];

    for (int i = 0; i < 8; i++) {
        string resArr[4];
        getResult(arraySizes[i], resArr);
        for (int j = 0; j < 4; j++) {
            resultArray[i][j] = resArr[j];
        }
    }

    printHeader("insertionSort");
    for (int j = 0; j < 8; j++) {
        cout << resultArray[j][0] << endl;
    }

    printHeader("mergeSort");
    for (int j = 0; j < 8; j++) {
        cout << resultArray[j][1] << endl;
    }

    printHeader("quickSort");
    for (int j = 0; j < 8; j++) {
        cout << resultArray[j][2] << endl;
    }

    printHeader("radixSort");
    for (int j = 0; j < 8; j++) {
        cout << resultArray[j][3] << endl;
    }

}
