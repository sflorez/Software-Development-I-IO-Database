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
	string targetName;
	string targetPass;

	myDataBase.seekg(ios::beg);

	while(!myDataBase.eof())
	{
		myDataBase >> targetDB;
		if( db == targetDB)
		{
			myDataBase >> targetName >> targetPass >> shift;
			cout << "Database found" << endl;

			if( user == targetName && password == targetPass)
			{
				cout << "Successfully accessed the database" << endl;
				dataBaseInUse = db;
				connected = true;
				//int numKeys;
				string tempKey;
				int tempPos = 0;
				int tempLength = 0;
				getline( myDataBase, tempKey);
				myDataBase >> keysInVect;
				cout << keysInVect << endl;
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
				break;
			}

		}
		else
		{
			cout << "could not find the database" << endl;
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

	int length = theKeys.size();
	cout << length << endl;
	vector<Key*> temp = theKeys;
	mergeSort( theKeys, temp , 0 , length -1);

	while(!myDataBase.eof())
	{

			getline( myDataBase , inbuf);
			myTempFile << inbuf << endl;

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
	//stub for the close method should close out of the current database
	//synchronize();
	connected = false;
}
/*
 * we decided not to handle out DB exceptions like this
int SimpleDB::errorNum()
{
	// stub for the errorNum method
	return 0;
}

const string & SimpleDB::errorMessage()
{
	return "Invalid string input";
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
	if(binarySearch( theKeys, key)==-1)
	{
		cout << "key not found" << endl;
	}
	else
	{
		index = binarySearch(theKeys, key);
	}

	int position = theKeys[index]->getPos();
	cout << "position: " << position << endl;
	int length = theKeys[index]->getLength();
	cout << "length: " << length << endl;

	char* buf = new char();

	fstream myDataFile( dataFileInUse, ios:: in);

	myDataFile.seekg(0 , myDataFile.beg);
	myDataFile.seekg(position , myDataFile.cur);
	myDataFile.read(buf, length);

	Algorithm::decrypt(buf,shift);

	cout << buf << endl;

	return buf;
}

bool SimpleDB::update( const char *key, const char *value)
{
	    int index = 0;
	    int valueLength = strlen(value);

		if(binarySearch( theKeys, key) == -1)
		{
			cout << "key not found" << endl;
			return false;
		}
		else
		{
			index = binarySearch(theKeys, key);
		}

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

			int position = theKeys[index]->getPos();
			cout << position << endl;
			int length = theKeys[index]->getLength();
			cout << length << endl;
			theKeys.erase(theKeys.begin()+ index);
			int posIndex;

			char charBuf;
			while(!myDataFile.eof())
			{
				posIndex = myDataFile.tellg();

				if(posIndex == position)
				{
					for( int i = 0 ; i < valueLength; i ++)
					{
						myDataFile.get();
						myTempDataFile.put(value[i]);
					}
				}
				charBuf = myDataFile.get();
				myTempDataFile << charBuf;
			}
		}

		remove( dataFileInUse);
		rename( "tempData2" , dataFileInUse);
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

		//find the next postion within the dataFile.
		myDataFile.seekg( 0 , myDataFile.end);
		int position = myDataFile.tellg();

		int length = strlen(value);
		string inbuf;
		myDataBase.seekg(ios::beg);

		while(!myDataBase.eof())
		{
			getline( myDataBase , inbuf);
			myTempFile << inbuf << endl;

			if(!inbuf.find(dataBaseInUse))
			{
				//add the key
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

		myDataFile << valueForData << endl;
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
				//add the key
				getline(myDataBase, inbuf);
				int keysInVect = atoi(inbuf.c_str());
				cout << keysInVect << endl;
				myTempFile << (keysInVect -1) << endl;

				for ( int i = 0 ; i < keysInVect ; i ++)
				{
					getline(myDataBase , inbuf);
					if(!inbuf.find(key))
					{
						//getline(myDataBase, inbuf);
						break;
					}

					myTempFile << inbuf << endl;
				}
			}
		}

		int position = theKeys[index]->getPos();
		cout << position << endl;
		int length = theKeys[index]->getLength();
		cout << length << endl;
		theKeys.erase(theKeys.begin()+ index);
		int posIndex;

		char charBuf;
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
//		myDataFile.seekp(position, myDataFile.cur);
//		for( int i = 0 ; i < length ; i ++)
//		{
//			myDataFile.put(' ');
//		}

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


