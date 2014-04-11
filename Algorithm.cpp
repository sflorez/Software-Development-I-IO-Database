#include "Algorithm.h"

using namespace std;

/*
 * default constructor
 */
Algorithm::Algorithm()
{}
/*
 *  Will check each character one at a time from a vector of strings.
 *  change them to ascii values from 32-126 shift it by 'n'
 *  the first shift and n+ (the initial n) until the it's done
 *  and return it to its encrypted form
*/
bool Algorithm::encrypt(char* data , int shift)
{
    //gives a base shift of 1
    if(shift <= 0)
    {
        shift = BASE_SHIFT;
    }
    
    // initial shift
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
            
			if(asciiVal + shift > 126)
			{
					asciiVal = ((asciiVal + shift) % 94) - 1;
			}
			else
			{
				asciiVal += shift;
			}

			data[i] = (char)asciiVal;
			
            shift += temp;
		}
	return true;
}

/*
 * Decrypts the encrypted data by subtracting
 * the ascii value from where it is when it is encrypted
 */
bool Algorithm::decrypt(char* data , int shift)
{
    
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
            
			if(asciiVal - shift < 32)
			{
               	asciiVal = (32 - (asciiVal - shift)) - 1;
                asciiVal = 126 - asciiVal;
			}
			else
			{
				asciiVal -= shift;
			}

			data[i] = (char)asciiVal;
			
            shift += temp;
		}
    
	return true;
}

Algorithm::~Algorithm(){}
