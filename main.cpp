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
	    int shift;
//	    const char* db = "sebastianDB";
//	    const char* user = "sebass";
//	    const char* password = "hello";

	    SimpleDB simpleDB( key, database);

//	    cout << "create a database! " << endl;
	    cout << "enter the name of the database, the username, and password "
	    		"with spaces in between" << endl;
	    cin >> tempName >> tempUser >> tempPass >> shift;
	    dataBaseName = tempName.c_str();
	    dataBaseUser = tempUser.c_str();
	    dataBasePass = tempPass.c_str();

 //       simpleDB.create(dataBaseName, dataBaseUser, dataBasePass, shift);

	    simpleDB.connect(dataBaseName, dataBaseUser, dataBasePass);

//	    cout<< "Enter the name for a key to insert" << endl;
//	    cin>> tempKeyName;
//	    keyName = tempKeyName.c_str();



//	    cout << "enter a key and a value to enter into the database" << endl;
//	    cin >> tempKeyName >> tempValueName;
//	    keyName = tempKeyName.c_str();
//	    value = tempValueName.c_str();
//
//	    simpleDB.insert( keyName, value);



//	    string search = "";
//	   	cout << "search for a key " << endl;
//	   	cin >> search;
//	   	cout << search << endl;
//	    const char* searchFor;
//	    searchFor = search.c_str();
//	    if(simpleDB.keyExists(searchFor))
//		{
//	    	cout << " key found " << endl;
//		}
//	    else{
//	    	cout << " key not found " << endl;
//	    }

//	    string erase;
//	    cout << " erase a key " << endl;
//	    cin >> erase;
//	    const char* toErase;
//	    toErase = erase.c_str();
//
//	    if(simpleDB.removeKey(toErase))
//	    {
//	    	cout << "true" << endl;
//	    }
//	    else
//	    {
//	    	cout << "false" << endl;
//	    }

//	    string tempdataKey;
//	    const char* dataKey;
//	    cout << " find data enter key " << endl;
//	    cin >> tempdataKey;
//	    dataKey = tempdataKey.c_str();
//
//	    cout << simpleDB.select(dataKey) << endl;

		string tempUpdateKey;
		string tempUpdateValue;
		const char* updateKey;
		const char* updateValue;
		cout << " key and value to update"  << endl;
		cin >> tempUpdateKey >> tempUpdateValue;
		updateKey = tempUpdateKey.c_str();
		updateValue = tempUpdateValue.c_str();

		if(simpleDB.update(updateKey, updateValue ) == false)
		{
			cout << "false" << endl;
		}
		else
		{
			cout << "true" << endl;
		}

	    return 0;
}


