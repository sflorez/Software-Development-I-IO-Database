/*
*	mergeSort.h
*
*/

#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
#include "Key.h"

/*
*	Member function that is called by mergeSort() to merge values
*/
void merge( std::vector<Key*> &keyVector, std::vector<Key*> &tempStorage, int low, int pivot, int high);

/*
*	Member function to sort the vector of keys for the current database
*/
void mergeSort(std::vector<Key*> &keyVector, std::vector<Key*> &tempStorage, int low, int high);

/*
 * Member function called by mergeSortLoc() to merge keys 
*/
void mergeLoc(std::vector<Key*> &keyVector, std::vector<Key*> &tempStorage, int low, int high);

/*
 * Member function to sort keys based on location in the database
*/
void mergeSortLoc(std::vector<Key*> &keyVector, std::vector<Key*> &tempStorage, int low, int high);

/*
*	Member function to search through the sorted vector of keys by their length, and
*	returns the key's location in the vector
*/
int binarySearch(std::vector<Key*> &iKeyVector, const char* iKey);

#endif
