/*
 * Key.cpp
 *
 *  Created on: Apr 2, 2014
 *
 */

#include "Key.h"
using namespace std;

Key::Key( string key, int pos, int length  )
{
	keyName = key;
	position = pos;
	lengthOfData = length;
}

const char* Key::getKey()
{
	return keyName.c_str();
}

void Key::setKey( string key)
{
	keyName = key;
}

const int Key::getPos()
{
	return position;
}

void Key::setPos( int pos)
{
	position = pos;
}

const int Key::getLength()
{
	return lengthOfData;
}

void Key::setLength(int length)
{
	lengthOfData = length;
}

long Key::getAsciiValue()
{
	return 0;
}

Key::~Key() {
	// TODO Auto-generated destructor stub
}

