#include "Key.h"
#include <cstring>
#include <vector>
using namespace std;
  
  
/*
 * Called in mergeSort()
 * Stores values from the vector containing the keys into a temporary storage vector as the
 *      keys are ordered.
 * Once completely ordered, the keys are then merged back into the original vector
 * Sorts based on the length of the keyName.
*/
  
int compareASCII(const char *iKey1, const char *iKey2)
{
    for( ; *iKey1 != '\0' && *iKey2 != '\0'; iKey1++, iKey2++)
    {
        if(*iKey1 < *iKey2)
        {
            return -1;
        }
        if(*iKey1 > *iKey2)
        {
            return 1;
        }
    }
    if(*iKey2 != '\0')
    {
        return -1;
    }
    else if(*iKey1 != '\0')
    {
       return 1;
    }
    else
    {
      return 0;
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
        //(int)keyVector[left]->getKey()) <= ...
        if(compareASCII(keyVector[left]->getKey(), keyVector[right]->getKey()) < 0)
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
  
     /*
      * Searches based on the length of the keyName.
      * Tweeked by Michael. Should take in a vector of Key objects and an int, stating the size of the key requested
      * Returns the int of the Key's location in the vector. 
     */
 int binarySearch(vector<Key*> &iKeyVector, const char* iKey)
     {
         int keyVectLength = iKeyVector.size();
         int keyLength = strlen(iKey);
         int low, high;
         low = 0;
         high = iKeyVector.size() - 1;
 
         while (low <= high)
         {
             int mid = (low + high) / 2;
             if (compareASCII(iKey, iKeyVector[mid]->getKey()) == 0)
             {
                 return mid;
             }
             else if (compareASCII(iKey, iKeyVector[mid]->getKey()) < 0)
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
