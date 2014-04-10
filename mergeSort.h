/*
*	mergeSort.h
*	Headerfile for mergeSort.cpp
*
*	Michael Fye
*/

#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
#include 'Key.h'

/*
*	Member function that is called by mergeSort() to merge values 
*/
void merge( vector<Key> &iKeyVector, int iLow, int iMid, int iHigh, vector<Key> &iTempStorage);

/*
*	Member function to sort the vector of keys for the current database
*/
void mergeSort(vector<Key> &iKeyVector, int iLow, int iHigh, vector<Key> &iTempStorage);

/*
*	Member function to search through the sorted vector of keys by their ASCII value, and 
*	returns the key's location in the vector
*/
int binarySearch(vector<Key> &iKeyVector, const char* iTerm);

#endif
