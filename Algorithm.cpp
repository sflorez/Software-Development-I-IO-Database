
#include "Algorithm.h"
using namespace std;

Algorithm::Algorithm()
{

}

/*
 *
 *  Will check each character one at a time from a vector of strings.
 *  change them to ascii values from 32-126 shift it by 'n' the first
 *  the first shift and n+n until the it's done
*/

static bool Algorithm::encrypt(const char* data , int shift)
{
    if(shift <= 0 || shift >= 126)
    {
        shift = BASE_SHIFT;
    }
    int temp = shift;

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

			shift += temp;
		}
	return true;
}

Algorithm::~Algorithm() {
    // TODO Auto-generated destructor stub
}

