#include 'Key.h'
#include <vector>

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
		if (iKeyVector[left] < iKeyVector[right])
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
}