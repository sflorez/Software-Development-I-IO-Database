#include "Key.h"
#include <cstring>
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
	 * Searches based on the length of the keyName.
	 * Tweeked by Michael. Should take in a vector of Key objects and an int, stating the size of the key requested
	 * Returns the int of the Key's location in the vector. 
	 * Returns -1 if the key is not found. 
	*/
int binarySearch(vector<Key*> &iKeyVector, int iKeyLength)
	{
		int keyVectLength = iKeyVector.size();
		int low, high;
		low = 0;
		high = iKeyVector.size() - 1;

		while (low <= high)
		{
				cout << "Ran through one stage" << endl;
			int mid = (low + high) / 2;
			if (strlen(iKeyVector[mid]->getKey()) == iKeyLength)
			{
				return mid;
			}
			else if (strlen(iKeyVector[mid]->getKey()) < iKeyLength)
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

