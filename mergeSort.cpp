#include "Key.h"
#include <vector>
using namespace std;

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
int compareASCII(const char* iKey1, const char* iKey2)
{
	for (unsigned int i = 0; i < strlen(iKey1) && i < strlen(iKey2); i++)
	{
		if ((int)(iKey1[i]) < (int)(iKey2[i]))
		{
			return -1;
		}
		else if ((int)(iKey1[i]) > (int)(iKey2[i]))
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
void merge(vector<Key*> &iKeyVector, int iLow, int iMid, int iHigh, vector<Key*> &iTempStorage)
{
	int left = iLow;
	int right = iMid + 1;

	int tempLow = iLow;

	while ((left <= iMid) && (right <= iHigh))
	{
		if (compareASCII(iKeyVector[left]->getKey(), iKeyVector[right]->getKey()) < 0)
		{
			iTempStorage.at(tempLow)= iKeyVector.at(left);
			left++;
		}
		else
		{
			iTempStorage.at(tempLow) = iKeyVector.at(right);
			right++;
		}
		tempLow ++;
	}

	if(left > iMid)
	{
		for ( unsigned int k = right ; k <= iHigh ; k ++ )
		{
			iTempStorage.at(tempLow) = iKeyVector.at(k);
			tempLow++;
		}

	}

	else
	{
		for( unsigned int k = left; k <=iMid; k ++)
		{
			iTempStorage.at(tempLow)= iKeyVector.at(k);
			tempLow++;
		}
	}

	for (tempLow = tempLow - 1; tempLow >= iLow; tempLow--)// changed --
	{
		iKeyVector.at(tempLow) = iTempStorage.at(tempLow);
	}
}

/*
 * mergeSort function. Requires a vector of keys, the beginning and end of the  segment (as an int to be used to reference the vector)
 *		and a temporary vector for storage to merge the keys
*/
void mergeSort(vector<Key*> &iKeyVector, int iLow, int iHigh, vector<Key*> &iTempStorage)
{
	int sortLow, sortMid, sortHigh;

	sortLow = iLow;
	sortHigh = iHigh;


	if (sortLow < sortHigh)
	{
		sortMid = (sortHigh + sortLow) / 2;

		mergeSort(iKeyVector, sortLow, sortMid, iTempStorage);
		mergeSort(iKeyVector, sortMid +1 , sortHigh , iTempStorage);
		merge(iKeyVector, sortLow, sortMid, sortHigh, iTempStorage);
	}

}

	/*
	 * binarySearch takes in a vector of key objects and a const char* iTerm.
	 * Searches through the vector and compares the ASCII values of the keys in the vector with iTerm
	 *
	 * Returns the position of the key in the vector if found
	 * Returns -1 if specified key does not exist
	*/
	int binarySearch(vector<Key> &iKeyVector, const char* iTerm)
	{
		int keyVectLength = iKeyVector.size();
		int low, high;
		low = 0;
		high = iKeyVector.size() - 1;

		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (compareASCII(iKeyVector[mid].getKey(), iTerm) == 0)
			{
				return mid;
			}
			else if (compareASCII(iKeyVector[mid].getKey(), iTerm) < 0)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		return -1;
	}

