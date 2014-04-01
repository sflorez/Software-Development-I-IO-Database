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
			myKeyFile << "hello" << endl;
			myDataFile.open( dataFileName);
			myDataFile << "the other stuff" << endl;
			myKeyFile.close();
			myDataFile.close();
	}

SimpleDB::~SimpleDB(){}
