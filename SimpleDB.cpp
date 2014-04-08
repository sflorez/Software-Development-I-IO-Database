#include <iostream>
#include <fstream>
#include "SimpleDB.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include "Key.h"
using namespace std;

	const char* keyFileName;
	const char* dataFileName;
	const char* keyFileInUse;
	const char* dataFileInUse;
	const char* dataBaseInUse;
	bool connected;
	vector<Key*> theKeys;

	/*The constructor for the SimpleDB class, creates a keyfile and
	 * datafile for the database.
	 *
	 * @params: keyfile and datafile
	 */
SimpleDB::SimpleDB( const string & keyFile , const string & dataFile)
	{
		keyFileName = keyFile.c_str();
		dataFileName = dataFile.c_str();
		dataFileInUse = "";
		dataBaseInUse = "";
		connected = false;


		ifstream file(keyFileName);
		if(!file) // the file was not found so create it.
		{
			ofstream myKeyFile(keyFileName);
			keyFileInUse = keyFileName;
			myKeyFile.close();
		}
		else   //if the file was found, use existing file
		{
			cout << " file already exists: Using the existing keyfile" << endl;
			keyFileInUse = keyFileName;
		}

		ifstream file2(dataFileName);
		if(!file) // the file was not found so create it.
		{
			ofstream myDataFile(dataFileName);
			dataFileInUse = dataFileName;
			myDataFile.close();
		}
		else   //if the file was found, use existing file
		{
			cout << " file already exists: Using the existing datafile" << endl;
			dataFileInUse = dataFileName;
		}

	}

SimpleDB::~SimpleDB(){}

void SimpleDB::create( const char* db, const char* user, const char* password, const int shift)
{
	int numKeys = 0;

	ofstream myDataBase;

	myDataBase.open( keyFileInUse, ios:: out | ios:: in | ios:: app);
	myDataBase << db << " " <<  user << " " <<  password << " " <<  shift << endl;
	myDataBase << numKeys << endl;

	myDataBase.close();
}

void SimpleDB::connect(const char* db, const char* user, const char* password)
{
	// stub for the connect method, should try to connect to an existing database within the
	// keyfile
	fstream myDataBase(keyFileInUse, ios:: out | ios::in);
	string targetDB;
	const char* userName;
	string targetName;
	string targetPass;
	const char* userPass;
	string tempName;
	string tempPass;

	myDataBase.seekg(ios::beg);

	while(!myDataBase.eof())
	{
		myDataBase >> targetDB;
		if( db == targetDB)
		{
			myDataBase >> targetName >> targetPass;
			cout << "Database found please enter credentials" << endl;
			cout << "Please enter the username and password of the database"
					" seperated by a space" << endl;
			cin >> tempName >> tempPass;
			userName = tempName.c_str();
			userPass = tempPass.c_str();

			if( userName == targetName && userPass == targetPass)
			{
				cout << "Successfully accessed the database" << endl;
				dataBaseInUse = db;
				connected = true;
				int numKeys;
				string tempKey;
				const char* key;
				int tempPos = 0;
				int tempLength = 0;
				getline( myDataBase, tempKey);
				myDataBase >> numKeys;
				cout << numKeys << endl;
				if( numKeys == 0 )
				{
					cout << "No keys in database" << endl;
				}
				else
				{
					for( int i = 0; i < numKeys; i ++)
					{
						myDataBase >> tempKey >> tempPos >> tempLength;
						key = tempKey.c_str();
						cout << key << endl;
						theKeys.push_back(new Key( key, tempPos, tempLength));
					}

				}
				break;
			}
			else
			{
				cout << "Incorrect username or password" << endl;
				break;
			}

		}
		else
		{
			cout << "could not find the database" << endl;
		}
	}

}

void SimpleDB::synchronize()
{
	//stub for the synchornize method
}

void SimpleDB::close()
{
	//stub for the close method should close out of the current database
	synchronize();
	connected = false;
}

int SimpleDB::errorNum()
{
	// stub for the errorNum method
	return 0;
}

const string & SimpleDB::errorMessage()
{
	return NULL;
}

bool SimpleDB::keyExists( const char* key)
{
	return false;
	//stub for the keyExists method
}

const char* SimpleDB::select(const char* key)
{
	return NULL;
	//stub for the select method
}

bool SimpleDB::update( const char *key, const char *value)
{
	return false;
}

bool SimpleDB::insert(const char* key , const char* value)
{
	string targetDB;

	if(!connected)
	{
		return false;
	}
	else
	{
		fstream myDataBase(keyFileInUse, ios:: out | ios::in);
		myDataBase.seekg(ios::beg);

		while(!myDataBase.eof())
		{
			myDataBase >> targetDB;
			if( dataBaseInUse == targetDB)
			{
				//add the key
				string numKeys;
				getline(myDataBase, numKeys);
				getline(myDataBase, numKeys);
				cout << numKeys << endl;
				int num = atoi(numKeys.c_str());
				cout << num << endl;
				int numToSeek = num + 3;
				if( num == 0)
				{
					cout << " in if" << endl;
					myDataBase.seekp(-numToSeek, ios::cur);
					int currentpos = myDataBase.tellp();
					myDataBase << (num+1) << endl;
					myDataBase.seekp(currentpos);
					getline(myDataBase, numKeys);
					myDataBase << key << " "<< 0 << " "<< 5 << endl;

					myDataBase.close();
					break;
				}
				else
				{
//					cout << " in else " << endl;
				myDataBase.seekp(-numToSeek, ios::cur);
				int currentpos = myDataBase.tellp();
				myDataBase << (num+1) << endl;
				myDataBase.seekp(currentpos);
				getline(myDataBase, numKeys);
					for( int i = 0 ; i < num ; i++)
					{
						getline(myDataBase, numKeys);
					}
					myDataBase << key <<" " <<  0 << " " << 5 << endl;
					break;
				}
			}
		}

		return true;

	}

}

bool SimpleDB::remove(const char* key)
{
	return false;
}



