/*
 * Algorithm.cpp
 * Author: Antonio Garcia
 * Created: 4/2/14
 */

#include<iostream>
#include "Algorithm.h"
using namespace std;

/*
 * constructor uses Caesar encryption with
 * ASCII values 32-126
 * encryption works with a multiple from 1-n based 
 * on the n of characters or from x-n 
 * if they enter an incorrect shift it will default to 1
 * 
 */

Algorithm::Algorithm() {
	static const int ASCII_MAX = 126;
	static const int ASCII_MIN = 32;
}

char* Algorithm::encrypt(char * data , int shift )
{
	// use strlen to find the size of the char* array
	int length = strlen(data);

	for(int i = 0; i < length; i++)
		{
			int asciiVal = ((int) *data);
			asciiVal = (asciiVal)*(shift);

			//not sure what you are trying to do
			//here but you cannot have an assignment on both sides
//			char* encVal = char*(asciiVal);

			shift = shift + 2;
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

