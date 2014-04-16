//Comments for the class functions are within the .h file.
#include "SimpleDB.h"
#include "Algorithm.h"
#include "mergeSort.h"

using namespace std;

int shift;

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
		keysInVect = 0;


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

void SimpleDB::create( const char* db, const char* user, const char* password, int shift)
{
	int numKeys = 0;

	ofstream myDataBase;

	//creates a new database with entered db name, username and password
	myDataBase.open( keyFileInUse, ios:: out | ios:: in | ios:: app);
	myDataBase << db << " " <<  user << " " <<  password << " " <<  shift << endl;
	myDataBase << numKeys << endl;

	myDataBase.close();
}

void SimpleDB::connect(const char* db, const char* user, const char* password)
{

	fstream myDataBase(keyFileInUse, ios:: out | ios::in);
	string targetDB;
	string targetName;
	string targetPass;

	myDataBase.seekg(ios::beg);

	//as long as the end of the file has not been reached function will look for the db entered
	while(!myDataBase.eof())
	{
		myDataBase >> targetDB;
		//if the database name entered matches one within the keyfile then connect to it.
		if( db == targetDB)
		{
			//grabs the username and password from the database that was found
			myDataBase >> targetName >> targetPass >> shift;
			cout << "Database found" << endl;

			//checks to see if the credentials entered match.
			if( user == targetName && password == targetPass)
			{
				cout << "Successfully accessed the database" << endl;
				dataBaseInUse = db;
				connected = true;
				string tempKey;
				int tempPos = 0;
				int tempLength = 0;
				getline( myDataBase, tempKey);
				myDataBase >> keysInVect;
				cout << keysInVect << endl;

				//checks to see if there are any keys within the database if so then it adds the keys to the key vector
				if( keysInVect == 0 )
				{
					cout << "No keys in database" << endl;
				}
				else
				{
					for( int i = 0; i < keysInVect; i ++)
					{
						myDataBase >> tempKey >> tempPos >> tempLength;
						theKeys.push_back(new Key( tempKey, tempPos, tempLength));
					}

					for( int i = 0; i < keysInVect; i ++)
					{
						cout << theKeys[i]->getKey() <<" "<< theKeys[i]->getPos() << " " << theKeys[i]->getLength()<< endl;

					}
				}
				break;
			}
			else
			{
				cout << "Incorrect username or password" << endl;
                throw userPassException();
				break;
			}

		}
		else
		{
			cout << "searching for database" << endl;
		}
	}

	myDataBase.close();

}

void SimpleDB::synchronize()
{

	fstream myDataBase(keyFileInUse, ios:: out | ios::in);
	ofstream myTempFile("tempFile", ios :: out);
	myDataBase.seekg(ios::beg);
	string inbuf;

	//merges the keys within the vector then writes them back out to the keyfile in sorted order
	int length = theKeys.size();
	vector<Key*> temp = theKeys;
	mergeSort( theKeys, temp , 0 , length -1);

	while(!myDataBase.eof())
	{

		getline( myDataBase , inbuf);
		myTempFile << inbuf << endl;

		//uses inbuf to check for the database currently in use then writes that database's keys back to keyfile
		//in sorted order.
		if(!inbuf.find(dataBaseInUse))
		{
			//add the key
			getline(myDataBase, inbuf);
			myTempFile << inbuf << endl;

			for( int i = 0 ; i < length ; i ++)
			{
				myTempFile << theKeys[i]->getKey() << " " << theKeys[i]->getPos() << " " << theKeys[i]->getLength() << endl;
			}

			for ( int i = 0 ; i < length ; i ++)
			{
				getline(myDataBase, inbuf);
			}

		}

	}

	myTempFile.close();
	myDataBase.close();

	remove(keyFileInUse);
	rename("tempFile" , keyFileInUse);
}

void SimpleDB::close()
{
	connected = false;
}
/*
int SimpleDB::errorNum()
{
	// stub for the errorNum method
	return 0;
}

const string & SimpleDB::errorMessage()
{
	return "Invalid string input?";
}
*/
bool SimpleDB::keyExists( const char* key)
{

	if(binarySearch(theKeys, key) == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

const char* SimpleDB::select(const char* key)
{
	int index = 0;
	//first looks for the existance of the key.
	if(binarySearch( theKeys, key)==-1)
	{
		cout << "key not found" << endl;
		return NULL;
	}
	else
	{
		//sets index to the location of that key within the vector
		index = binarySearch(theKeys, key);
	}

	//grabs the position and length within the datafile for that specific key
	int position = theKeys[index]->getPos();
	int length = theKeys[index]->getLength();

	char* buf = new char();

	fstream myDataFile( dataFileInUse, ios:: in);

	//finds the data associated with that key within the datafile then reads it into the buf
	myDataFile.seekg(0 , myDataFile.beg);
	myDataFile.seekg(position , myDataFile.cur);
	myDataFile.read(buf, length);

	Algorithm::decrypt(buf,shift);

	return buf;
}

bool SimpleDB::update( const char *key, const char *value)
{
	    int index = 0;
	    int valueLength = strlen(value);
	    int keyLength;

	    //checks for the keys existance
		if(binarySearch( theKeys, key) == -1)
		{
			cout << "key not found" << endl;
			return false;
		}
		else
		{
			index = binarySearch(theKeys, key);
		}

		//checks to see if the space available is enough to put the new value in
		keyLength = theKeys[index]->getLength();
		if( valueLength > theKeys[index]->getLength())
		{
			cout << " value is longer than space available" << endl;
			return false;
		}
		else
		{
			fstream myDataFile;
			myDataFile.open(dataFileInUse, ios:: out | ios:: in | ios::app);
			ofstream myTempDataFile( "tempData2", ios::out);

			//grabs the position and length from the key currently being worked with
			int position = theKeys[index]->getPos();
			int length = theKeys[index]->getLength();
			theKeys[index]->setLength(valueLength);

			int posIndex;
			char charBuf;
			char* valueForData = strdup(value);

			Algorithm::encrypt(valueForData , shift);

			//looks for the position of the data that needs to be updated
			while(!myDataFile.eof())
			{
				posIndex = myDataFile.tellg();
				cout << posIndex << endl;

				//updates the data if it finds the position of the data being searched for
				if(posIndex == position)
				{
					for( int i = 0 ; i < valueLength; i ++)
					{
						myDataFile.get();
						myTempDataFile.put(valueForData[i]);
					}

					for( int i = 0 ; i < (keyLength - valueLength) ; i ++)
					{
						myDataFile.get();
						myTempDataFile.put(' ');
					}
				}
				charBuf = myDataFile.get();
				myTempDataFile << charBuf;
			}
		}

		remove( dataFileInUse);
		rename( "tempData2" , dataFileInUse);
		synchronize();
		return true;
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
		ofstream myTempFile("tempFile", ios :: out);
		fstream myDataFile;
		myDataFile.open(dataFileInUse, ios:: out | ios:: in | ios::app);

		//find the next position within the dataFile.
		myDataFile.seekg( 0 , myDataFile.end);
		int position = myDataFile.tellg();

		int length = strlen(value);
		string inbuf;
		myDataBase.seekg(ios::beg);

		//writes from the original keyfile to the tempkeyfile as long as the end of file is not reached
		while(!myDataBase.eof())
		{
			getline( myDataBase , inbuf);
			myTempFile << inbuf << endl;

			if(!inbuf.find(dataBaseInUse))
			{
				//add the key to the keyfile and the key vector
				getline(myDataBase, inbuf);
				int keysInVect = atoi(inbuf.c_str());
				cout << keysInVect << endl;
				myTempFile << (keysInVect+1) << endl;
				myTempFile << key << " "<< position << " "<< length << endl;
				string keyName(key);
				theKeys.push_back(new Key( keyName, position, length));
			}
		}

		myTempFile.close();
		myDataBase.close();

		remove(keyFileInUse);
		rename("tempFile" , keyFileInUse);

		char* valueForData = strdup(value);

		Algorithm::encrypt(valueForData, shift);

		myDataFile << valueForData;
		myDataFile.close();
	}
	synchronize();
	return true;
}



bool SimpleDB::removeKey(const char* key)
{
	int index = 0 ;
	if( !connected)
	{
		return false;
	}
	else
	{
		if(binarySearch(theKeys, key) == -1)
		{
			return false;
		}
		else
		{
			index = binarySearch(theKeys, key);
		}

		fstream myDataBase(keyFileInUse, ios:: out | ios::in);
		ofstream myTempFile("tempFile", ios :: out);
		fstream myDataFile;
		myDataFile.open(dataFileInUse, ios:: out | ios:: in | ios::app);
		ofstream myTempDataFile( "tempData", ios::out);

		string inbuf;
		myDataBase.seekg(ios::beg);


		while(!myDataBase.eof())
		{
			getline( myDataBase , inbuf);
			myTempFile << inbuf << endl;

			if(!inbuf.find(dataBaseInUse))
			{
				//remove the key from the keyfile and the vector
				getline(myDataBase, inbuf);
				int keysInVect = atoi(inbuf.c_str());
				cout << keysInVect << endl;
				myTempFile << (keysInVect -1) << endl;

				for ( int i = 0 ; i < keysInVect ; i ++)
				{
					getline(myDataBase , inbuf);
					if(!inbuf.find(key))
					{
						break;
					}

					myTempFile << inbuf << endl;
				}
			}
		}

		int position = theKeys[index]->getPos();
		int length = theKeys[index]->getLength();
		theKeys.erase(theKeys.begin()+ index);
		int posIndex;

		char charBuf;
		//deletes the data associated with the key that was removed.
		while(!myDataFile.eof())
		{
			posIndex = myDataFile.tellg();

			if(posIndex == position)
			{
				for( int i = 0 ; i < length; i ++)
				{
					myDataFile.get();
					myTempDataFile.put('\0');
				}
			}
			charBuf = myDataFile.get();
			myTempDataFile << charBuf;
		}

		myDataBase.close();
		myTempFile.close();
		myDataFile.close();
		myTempDataFile.close();

		remove( keyFileInUse);
		rename("tempFile" , keyFileInUse);

		remove( dataFileInUse);
		rename( "tempData" , dataFileInUse);


	}
	return true;
}


