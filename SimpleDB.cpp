#include <iostream>
#include <fstream>
#include "SimpleDB.h"
#include <cstring>
using namespace std;

	/*The constructor for the SimpleDB class, creates a keyfile and
	 * datafile for the database.
	 *
	 * @params: keyfile and datafile
	 */
SimpleDB::SimpleDB( const string & keyFile , const string & dataFile)
	{
	ofstream myKeyFile;
			ofstream myDataFile;

			const char* keyFileName = keyFile.c_str();
			const char* dataFileName = dataFile.c_str();

			myKeyFile.open( keyFileName);
			myDataFile.open( dataFileName);
			myKeyFile.close();
			myDataFile.close();
	}

SimpleDB::~SimpleDB(){}

void SimpleDB::create( const char* db, const char* user, const char* password, const int shift)
{
	const char* dataBase = db;
	const char* username = user;
	const char* pass = password;
	int numKeys = 0;

	ofstream myDataBase;

	myDataBase.open( keyFileName, ios:: out);
	myDataBase << dataBase << ", " << username << ", " << pass << ", " << shift << endl;
	myDataBase << numKeys << endl;

	myDataBase.close();


}
