#include "Key.h"
#include <vector>
using namespace std;


/*
 * Called in mergeSort()
 * Stores values from the vector containing the keys into a temporary storage vector as the
 *		keys are ordered.
 * Once completely ordered, the keys are then merged back into the original vector
 * Sorts based on the length of the keyName.
*/
void merge(vector<Key*> &keyVector,vector<Key*> &tempStorage, int low, int pivot, int high );
void mergeSort(vector<Key*> &keyVector, vector<Key*> &tempStorage, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergeSort( keyVector, tempStorage,low,pivot);
        mergeSort(keyVector,tempStorage,pivot+1,high);
        merge(keyVector,tempStorage,low,pivot,high);
    }
}
void merge(vector<Key*> &keyVector, vector<Key*> &tempStorage, int low, int pivot, int high)
{
    int left,tempLow,right,k;
    left=low;
    tempLow=low;
    right=pivot+1;

    while((left<=pivot)&&(right<=high))
    {
        if(strlen(keyVector[left]->getKey())<= strlen(keyVector[right]->getKey()))
        {
            tempStorage[tempLow]=keyVector[left];
            left++;
        }
        else
        {
            tempStorage[tempLow]=keyVector[right];
            right++;
        }
        tempLow++;
    }
    if(left>pivot)
    {
        for(k=right; k<=high; k++)
        {
            tempStorage[tempLow]= keyVector[k];
            tempLow++;
        }
    }
    else
    {
        for(k=left; k<=pivot; k++)
        {
            tempStorage[tempLow]=keyVector[k];
            tempLow++;
        }
    }
    for(k=low; k<=high; k++)
    	{
    		keyVector[k]=tempStorage[k];
    	}
}

	/*
	 * Should search based on the length of the keyName.
	*/
//	int binarySearch(vector<Key> &iKeyVector, const char* iTerm)
//	{
//		int keyVectLength = iKeyVector.size();
//		int low, high;
//		low = 0;
//		high = iKeyVector.size() - 1;
//
//		while (low <= high)
//		{
//			int mid = (low + high) / 2;
//			if (compareASCII(iKeyVector[mid].getKey(), iTerm) == 0)
//			{
//				return mid;
//			}
//			else if (compareASCII(iKeyVector[mid].getKey(), iTerm) < 0)
//			{
//				high = mid - 1;
//			}
//			else
//			{
//				low = mid + 1;
//			}
//		}
//		return -1;
//	}

