/*
 * Algorithm.cpp
 * Author: Antonio Garcia
 * Created: 4/2/14
 */

#include<iostream>
#include "Algorithm.h"
using namespace Algorithm;

/*
 * constructor uses Caesar encryption with
 * ASCII values 32-126
 *
 *   
 */
Algorithm()
{
	
}

static int add(int a, int b){return a+b;}
char encrypt(char* data, int shift)
{

	for(int i = 0; i < *data.length; i++)
	{
		int asciiVal = ((int) *data);
		asciiVal = (asciiVal)*(shift);
		char* encVal = char*(asciiVal);
		shift = shift + 2;
		return *encVal;
	}
	
}

char decrypt(char* data, int shift)
{
	for(int j = 0; j < *data; j++)
	{
		int *asciiVal = ((int)*data);
		asciiVal = (asciiVal)*(shift);
		char* decVal = char*(asciiVal);
		shift = shift + 2;	
		return *decVal;
	}
}

/*
 * Encryption algorithm will shift the current 
 * ascii value in a for loop by the power of 2
 */
bool encrypt(char* data, int shift)
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

bool decrypt(char* data, int shift)
{
	for(int j = 0; j < *data; j++)
	{
		int *asciiVal = ((int)*data);
		asciiVal = (asciiVal)*(shift);

		shift = shift + 2;	
	}
}

~Algorithm()
{

}

