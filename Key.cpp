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
int position;
int lengthOfData;

Key::Key( const char* key, int pos, int length  )
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

