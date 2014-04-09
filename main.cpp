#include<iostream>
#include "SimpleDB.h"
#include <string>
using namespace std;
// testing commits from eclipse

int main()
{
	    const string &key = "keyFile";
	    const string &database = "DataFile";
	    const char* dataBaseName;
	    const char* dataBaseUser;
	    const char* dataBasePass;
	    const char* keyName;
	    const char* value;
	    string tempKeyName;
	    string tempValueName;
	    string tempName, tempUser, tempPass;
	    const int shift = 12;
//	    const char* db = "sebastianDB";
//	    const char* user = "sebass";
//	    const char* password = "hello";

	    SimpleDB simpleDB( key, database);

//	    cout << "create a database! " << endl;
	    cout << "enter the name of the database, the username, and password "
	    		"with spaces in between" << endl;
	    cin >> tempName >> tempUser >> tempPass;
	    dataBaseName = tempName.c_str();
	    dataBaseUser = tempUser.c_str();
	    dataBasePass = tempPass.c_str();

//	    simpleDB.create(dataBaseName, dataBaseUser, dataBasePass, shift);

	    simpleDB.connect(dataBaseName, dataBaseUser, dataBasePass);

//	    cout<< "Enter the name for a key to insert" << endl;
//	    cin>> tempKeyName;
//	    keyName = tempKeyName.c_str();
//
//

	    cout << "enter a key and a value to enter into the database" << endl;
	    cin >> tempKeyName >> tempValueName;
	    keyName = tempKeyName.c_str();
	    value = tempValueName.c_str();

	    simpleDB.insert( keyName, value);

	    return 0;
}


