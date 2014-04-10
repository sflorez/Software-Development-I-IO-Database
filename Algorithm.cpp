/*
 * Algorithm.cpp
 * Author: Antonio Garcia
 * Created: 4/2/14
 */

#include<iostream>
#include "Algorithm.h"
using namespace std;
/*
char* encrypt(char* data, int shift);
char* decrypt(char* data, int shift); 
bool decrypt(char* data, int shift);
bool encrypt(char* data, int shift);
char* encrypt(char* data, int shift);
char* decrypt(char* data, int shift);
bool encrypt(char* data, int shift);
bool decrypt(char* data, int shift);
*/

/*
 * constructor uses Caesar encryption with
 * ASCII values 32-126
 * encryption works with a multiple from 1-n based 
 * on the n of characters or from x-n 
 * if they enter an incorrect shift it will default to 1
 * 
 */
int Algorithm::Algorithm()
{
   // static const int ASCII_MAX = 126;
   // static const int ASCII_MIN = 32;
    
	//char* word = "hello";
    cout<< "Hi it works";
	return 0;
    //cout<< encrypt(word,2);
}
/*
char* Algorithm::encrypt(char* data, int shift)
{

	for(int i = 0; i < *data.length; i++)
	{
		int asciiVal = ((int) *data);
		asciiVal = (asciiVal)*(shift);
	//	char* encVal = char*(asciiVal);
		shift = shift + 2;
		return "nothing";
	}
}

char* Algorithm::decrypt(char* data, int shift)
{
	for(int j = 0; j < *data; j++)
	{
		int *asciiVal = ((int)*data);
		asciiVal = (asciiVal)*(shift);
	//	char* decVal = char*(asciiVal);
	   	shift = shift + 2;
		return *decVal;
	}
}

 *
 * Encryption algorithm will shift the current
 * ascii value in a for loop by the power of 2
 *
bool Algorithm::encrypt(char* data, int shift)
{

	for(int i = 0; i < *data.length; i++)
	{
		//will this increment the position of the char?
		int asciiVal = ((int) *data);
		asciiVal = (asciiVal)*(shift);
		char* encVal = char*(asciiVal);
		if()
		{

		}
		shift = shift + 2;
	}
}

bool Algorithm::decrypt(char* data, int shift)
{
	for(int j = 0; j < *data; j++)
	{
		int *asciiVal = ((int)*data);
		asciiVal = (asciiVal)*(shift);

		shift = shift + 2;
	}
}

Algorithm::~Algorithm()
{} 
*/
