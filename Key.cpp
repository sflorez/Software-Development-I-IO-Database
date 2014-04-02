/*
 * Key.cpp
 *
 *  Created on: Apr 2, 2014
 *
 */

#include "Key.h"
#include <iostream>
using namespace std;

const char* keyName;
const char* position;
const int lengthOfData;

Key::Key( const char* key, const int pos, const int length  )
{
	setKey(key);
	setPos(pos);
	setLength(length);

}

const char* Key::getKey()
{
	return keyName;
}

void Key::setKey( const char* key)
{
	keyName = key;
}

const int Key::getPos()
{
	return position;
}

void Key::setPos( const int pos)
{
	position = pos;
}

const int Key::getLength()
{
	return lengthOfData;
}

void Key::setLength( const int length)
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

