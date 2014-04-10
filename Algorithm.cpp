
#include "Algorithm.h"
#include <iostream>

using namespace std;

Algorithm::Algorithm() 
{
	static const int ASCII_MAX = 126;
	static const int ASCII_MIN = 32;
    static const int BASE_SHIFT = 1;
}


/*
 *
 *  Will check each character one at a time from a vector of strings.
 *  change them to ascii values from 32-126 shif it by 'n' the first
 *  the first shift and n+n until the it's done 
*/

char* Algorithm::encrypt(char * data , int shift)
{
    if(shift <= 0)
    {
        shift = BASE_SHIFT;
    }
	// use strlen to find the size of the char* array
	int length = strlen(data);

	for(int i = 0; i < length; i++)
		{
			int asciiVal = ((int) *data);
			asciiVal = (asciiVal)*(shift);

			//not sure what you are trying to do
			//here but you cannot have an assignment on both sides
//			char* encVal = char*(asciiVal);

			shift = shift + shift;
		}
	return "nothing";
}

char* Algorithm::decrypt(char* data , int shift )
{
	// again use strlen to find the size of the char* array
	int length = strlen(data);
	for(int j = 0; j < length; j++)
		{

			//this does not work
//			int *asciiVal = ((int)*data);
//			asciiVal = (asciiVal)*(shift);

			//same issue as above
//			char* decVal = char*(asciiVal);

		   	shift = shift + 2;
		}
	return "nothing";
}

bool Algorithm::canEncrypt(char* data , int shift )
{
	int length = strlen(data);
	for(int i = 0; i < length; i++)
		{
			//will this increment the position of the char?
			int asciiVal = ((int) *data);
			asciiVal = (asciiVal)*(shift);

			//same as the other methods let me know what you are trying to do
//			char* encVal = char*(asciiVal);
//			if()
//			{
//
//			}

			shift = shift + 2;
		}
	return false;
}

bool Algorithm::canDecrypt(char* data , int shift )
{
	int length = strlen(data);
	for(int j = 0; j < length; j++)
		{
			//this also does not work
//			int *asciiVal = ((int)*data);
//			asciiVal = (asciiVal)*(shift);

			shift = shift + 2;
		}
	return false;
}

Algorithm::~Algorithm() {
    // TODO Auto-generated destructor stub
}

