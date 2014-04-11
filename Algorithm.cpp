
#include "Algorithm.h"


using namespace std;

Algorithm::Algorithm()
{

}


/*
 *
 *  Will check each character one at a time from a vector of strings.
 *  change them to ascii values from 32-126 shif it by 'n' the first
 *  the first shift and n+n until the it's done
*/

static bool Algorithm::encrypt(const char* data , int shift)
{
    if(shift <= 0 || shift >= 126)
    {
        shift = BASE_SHIFT;
    }

	// use strlen to find the size of the char* array
	int length = strlen(data);

	for(int i = 0; i < length; i++)
		{
			int asciiVal = ((int) data[i]);

			if(asciiVal < 32 || asciiVal > 126)
			{
					return false;
			}
			//Check to make sure shifted value will not be greater
			//than 126
			if(asciiVal + shift > 126)
			{
					asciiVal = ((asciiVal + shift) % 94) - 1;
			}
			else
			{
				asciiVal += shift;
			}

			//not sure what you are trying to do
			//here but you cannot have an assignment on both sides
//			char* encVal = char*(asciiVal);

			data[i] = (char)asciiVal;
//          
//          this need to have a temp value to hold the initial shift to add it to the new shift
//          
			shift += shift;
		}
	return true;
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

