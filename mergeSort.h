/*
*	mergeSort.h
*	Headerfile for mergeSort.cpp
*
*/

#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
#include "Key.h"

/*
*	Member function that is called by mergeSort() to merge values
*/
void merge( std::vector<Key*> &iKeyVector, int iLow, int iMid, int iHigh, std::vector<Key*> &iTempStorage);

/*
*	Member function to sort the vector of keys for the current database
*/
void mergeSort(std::vector<Key*> &iKeyVector, int iLow, int iHigh, std::vector<Key*> &iTempStorage);

/*
*	Member function to search through the sorted vector of keys by their ASCII value, and
*	returns the key's location in the vector
*/
int binarySearch(std::vector<Key*> &iKeyVector, const char* iTerm);

#endif
