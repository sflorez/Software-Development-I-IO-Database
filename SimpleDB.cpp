#include <iostream>
#include <fstream>
using namespace std;

class SimpleDB
{
	/*The constructor for the SimpleDB class, creates a keyfile and
	 * datafile for the database.
	 *
	 * @params: keyfile and datafile
	 */
	SimpleBD::SimpleBD( const string & keyFile , const string & dataFile)
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
