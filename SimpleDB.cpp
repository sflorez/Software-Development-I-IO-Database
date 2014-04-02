#include <iostream>
#include <fstream>
#include "SimpleDB.h"
#include <string>
#include <vector>
using namespace std;

const char* keyFileName;
const char* dataFileName;

	/*The constructor for the SimpleDB class, creates a keyfile and
	 * datafile for the database.
	 *
	 * @params: keyfile and datafile
	 */
SimpleDB::SimpleDB( const string & keyFile , const string & dataFile)
	{
		keyFileName = keyFile.c_str();
		dataFileName = dataFile.c_str();

		ofstream myKeyFile(keyFileName);
		ofstream myDataFile(dataFileName);

	}

SimpleDB::~SimpleDB(){}

void SimpleDB::create( const char* db, const char* user, const char* password, const int shift)
{
	int numKeys = 0;

		fstream myDataBase;

		myDataBase.open( keyFileName, ios:: out | ios:: app);
		myDataBase << db << ", " << user << ", " << password << ", " << shift << endl;
		myDataBase << numKeys << endl;


}

void SimpleDB::connect(const char* db, const char* user, const char* password)
{
	// stub for the connect method, should try to connect to an existing database within the
	// keyfile
}

void SimpleDB::synchronize()
{
	//stub for the synchornize method
}

void SimpleDB::close()
{
	//stub for the close method should close out of the current database
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
	return false;
}

bool SimpleDB::remove(const char* key)
{
	return false;
}
