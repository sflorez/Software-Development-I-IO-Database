#include <iostream>
#include <fstream>
#include "SimpleDB.h"
using namespace std;

class SimpleDB
{
	/*The constructor for the SimpleDB class, creates a keyfile and
	 * datafile for the database.
	 *
	 * @params: keyfile and datafile
	 */
	SimpleDB::SimpleDB( const string & keyFile , const string & dataFile)
	{
		ofstream myKeyFile;
		ofstream myDataFile;

		string keyFileName = keyFile + ".txt";
		string dataFileName = dataFile + ".txt";

		myKeyFile.open( keyFileName);
		myDataFile.open( dataFileName);
		myKeyFile.close();
		myDataFile.close();
	}
};
