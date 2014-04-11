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

    //gives a base shift of
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

			else if(asciiVal + shift > 126)
			{
//				cout << asciiVal << endl;
//				asciiVal = ((asciiVal + shift) % 94) ;
//				cout << asciiVal << endl;
				do
				{
					asciiVal = ( asciiVal + shift ) - 126;
					asciiVal = 32 + asciiVal;
				}while( asciiVal > 126);
			}
			else if( asciiVal + shift < 32)
			{
				do{
					asciiVal = (32 - (asciiVal - shift));
					asciiVal = 126 - asciiVal;

				}while(asciiVal < 32);
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

			else if(asciiVal - shift < 32)
			{
//					cout << asciiVal << endl;
//					asciiVal = (asciiVal- shift  % 94) ;
				do{
					asciiVal = (32 - (asciiVal - shift));
					asciiVal = 126 - asciiVal;

				}while(asciiVal < 32);

			}
			else if( asciiVal - shift > 126 )
			{
				do
				{
					asciiVal = ( asciiVal + shift ) - 126;
					asciiVal = 32 + asciiVal;
				}while( asciiVal > 126);
			}
			else
			{
				asciiVal -= shift;
			}

//			cout << asciiVal << endl;
			data[i] = (char)asciiVal;

            shift += temp;

		}
	return true;
}

Algorithm::~Algorithm(){}
