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
	const char* dataBase = db;
	const char* username = user;
	const char* pass = password;
	int numKeys = 0;

	fstream myDataBase;

	myDataBase.open( keyFileName, ios:: out);
	myDataBase << dataBase << ", " << username << ", " << pass << ", " << shift << endl;
	myDataBase << numKeys << endl;

	myDataBase.close();


}
