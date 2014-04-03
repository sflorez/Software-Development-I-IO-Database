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
	    string tempName, tempUser, tempPass;
	    const int shift = 12;
//	    const char* db = "sebastianDB";
//	    const char* user = "sebass";
//	    const char* password = "hello";

	    SimpleDB simpleDB( key, database);

	    cout << "create a database! " << endl;
	    cout << "enter the name of the database, the username, and password "
	    		"with spaces in between" << endl;
	    cin >> tempName >> tempUser >> tempPass;
	    dataBaseName = tempName.c_str();
	    dataBaseUser = tempUser.c_str();
	    dataBasePass = tempPass.c_str();

//	    simpleDB.create(dataBaseName, dataBaseUser, dataBasePass, shift);

//	    simpleDB.connect(dataBaseName, dataBaseUser, dataBasePass);



	    return 0;
}


