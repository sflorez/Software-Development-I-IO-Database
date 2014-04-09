#include 'Key.h'
#include <vector>

/*
 * Compares two keys character by character. If it detects any character difference, 
 * it computes the difference and determines which string should occur first in alphabetical
 * order. 
 * If the strings are equivalent up until a point where one string is longer than the other, 
 * the longer string will return a larger value.
 * A return of -1 means the object should occur first.
 * A return of 1 means the object should occur last.
 * A return of 0 means the two objects are identical.
*/
int compareASCII(const char* &iKey1, const char* &iKey2)
{
	for (int i = 0; i < strlen(iKey1) && i < strlen(iKey2); i++)
	{
		if (static_cast<int>(iKey1[i]) < static_cast<int>(iKey2[i]))
		{
			return -1;
		}
		else if (static_cast<int>(iKey1[i]) > static_cast<int>(iKey2[i]))
		{
			return 1;
		}
	}

	if (strlen(iKey1) < strlen(iKey2))
	{
		return -1;
	}
	else if (strlen(iKey1) > strlen(iKey2))
	{
		return 1;
	}

	return 0;
}

/*
 * Called in mergeSort()
 * Stores values from the vector containing the keys into a temporary storage vector as the 
 *		keys are ordered.
 * Once completely ordered, the keys are then merged back into the original vector
*/
void merge(vector<Key> &iKeyVector, int iLow, int iMid, int iHigh, vector<Key> &iTempStorage)
{
	int left = iLow;
	int right = iMid + 1;

	int temp = iLow;

	while ((left <= iMid) && (right <= iHigh))
	{
		if (compareASCII(iKeyVector[left].getKey(), iKeyVector[right].getKey()) < 0)
		{
			iTempStorage[temp++] = iKeyVector[left++];
		}
		else
		{
			iTempStorage[temp++] = iKeyVector[right++];
		}
	}

	while (left <= iMid)
	{
		iTempStorage[temp++] = iKeyVector[left++];
	}

	while (right <= iHigh)
	{
		iTempStorage[temp++] = iKeyVector[right++];
	}

	for (temp = temp - 1; temp >= iLow; --temp)
	{
		iKeyVector[temp] = iTempStorage[temp];
	}
}

/*
 * mergeSort function. Requires a vector of keys, the beginning and end of the  segment (as an int to be used to reference the vector)
 *		and a temporary vector for storage to merge the keys 
*/
void mergeSort(vector<Key> &iKeyVector, int iLow, int iHigh, vector<Key> &iTempStorage)
{
	int sortLow, sortMid, sortHigh;

	sortLow = 0;
	sortHigh = iKeyVector.size;

	if (sortLow < sortHigh)
	{
		sortMid = (sortHigh - sortLow) / 2;

		mergeSort(iKeyVector, sortLow, sortMid, tempStorage);
		mergeSort(iKeyVector, ++sortMid, sortHigh);
		merge(iKeyVector, sortLow, sortMid, sortHigh, tempStorage);
	}

	int binarySearch(const char* iTerm)
	{

	}
}