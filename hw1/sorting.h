/*
 * Title: Algorithm Efficiency and Sorting
 * Author: Ahmet Faruk Ulutas
 * ID: 21803717
 * Section: 1
 * Assignment: 1
 * Description: Source file for the sorting algorithms + performance analysis
 */

#ifndef sorting_h
#define sorting_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void insertionSort( int *arr , int arraysize , int &compCount , int &moveCount );
void quickSort( int* arr, int size, int& compCount, int &moveCount );
void mergeSort( int* arr, int size, int &compCount , int &moveCount );
void radixSort( int *arr , int arraySize );
void printArray(int *arr, int arraySize);
void performanceAnalysis();

#endif // SORTING_H
