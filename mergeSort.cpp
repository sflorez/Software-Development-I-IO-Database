#include 'Key.h'
#include <vector>

void merge(vector<Key> &iKeyVector, int iLow, int iHigh, vector<Key> &iTempStorage)
{

}
void mergeSort(vector<Key> &iKeyVector, int iLow, int iHigh, vector<Key> &iTempStorage)
{
	int sortLow, sortMid, sortHigh;
	vector<Key> tempStorage;

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