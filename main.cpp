#include<iostream>
#include "SimpleDB.h"
#include <string>
using namespace std;
// testing commits from eclipse

int main()
{
	    const string &key = "keyFile";
	    const string &database = "DataFile";

	    SimpleDB simpleDB( key, database);
	    return 0;
}

