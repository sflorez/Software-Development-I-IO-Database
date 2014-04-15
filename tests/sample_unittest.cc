#include <vector>
#include <limits.h>
#include <iostream>
#include <fstream>
#include "SimpleDB.h"
#include "Key.h"
#include "Algorithm.h"
#include "mergeSort.h"
#include "gtest/gtest.h"
using namespace std;
 
/*
 * Uses the test fixture to test the "constructorTester"
 * Using the _F alerts it to use the fixture.
 */
TEST( SimpleDB, ConstructorTest )
{
	const char* keyFileName = "keyFile";
	const char* dataFileName = "dataFile";
    SimpleDB simpleDB( keyFileName, dataFileName );
    ifstream file(keyFileName);
    ifstream file1(dataFileName);
  
    ASSERT_TRUE(file);
    ASSERT_TRUE(file1);
}

/*
 * Calls the "CreateTest"
 */
TEST( SimpleDB, CreateTest )
{
    const char* db = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    const char* keyFileName = "keyFile";
	const char* dataBaseFile = "dataFile";
    const int shift = 4;
	string correct = "TestDataBase TestUserName TestPassword 4"; 

    SimpleDB simpleDB(keyFileName, dataBaseFile);
    simpleDB.create( db, user, password, shift );
                  
    string buffer;
    ifstream file;
    file.open( keyFileName, ios::in );
    getline( file, buffer );
            
    ASSERT_EQ( correct, buffer );
}

/*
 * Calls the "ConnectTest" 
 */

TEST( SimpleDB, ConnectTest )
{
    const char* db = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    const char* keyFileName = "keyFile";
    const char* dataBaseFile = "dataFile";
 
    SimpleDB simpleDB( keyFileName, dataBaseFile );
    simpleDB.connect( db, user, password);
    ASSERT_FALSE( simpleDB.getConnect() );
    simpleDB.connect( db, user, password );
    ASSERT_TRUE( simpleDB.getConnect() );
}

/*
 * Called the "insert" in the fixture
 */

TEST( SimpleDB, InsertTest )
{
    const char* key = "key";
    const char* value = "value";
   	const char* db = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    const char* keyFileName = "keyFile";
	const char* dataBaseFile = "dataFile";
	
    const int shift = 4;
    SimpleDB simpleDB( keyFileName, dataBaseFile );
    simpleDB.connect( db, user, password);
    simpleDB.create( db, user, password, shift );
    ASSERT_TRUE( simpleDB.insert( key, value ) );
}

/*
 * Tests Encryption to passes with correct inputs
 */
TEST( AlgorithmTest, EncryptTest )
{
    char* data = new char[4];
    strcpy(data, "key1");
    int shift = 4;
    ASSERT_TRUE( Algorithm::encrypt( data, shift ) );
}

/*
 * Tests if encryption passes with correct inputs
 */
TEST( AlgorithmTest, DecryptTest )
{
    char* data = new char[4];
    strcpy(data, "key1");
    int shift = 4;
	ASSERT_TRUE( Algorithm::decrypt( data, shift) );
}

/*
 * Tests the bounds of the ascii values are within
 * 32-126
 */
TEST( AlgorithmTest, EncryptionAsciiBounds )
{
    char* data = new char[7];
    strcpy(data,"áBadKey");
    int shift = 3;
    ASSERT_FALSE( Algorithm::encrypt( data, shift ) );
}

/*
 * Tests the bounds of the ascii values are within
 * 32-126
 */
TEST( AlgorithmTest, DecryptionAsciiBounds )
{
    char* data = new char[7];
    strcpy(data, "áBadKey");
    int shift = 3;
    ASSERT_FALSE( Algorithm::encrypt( data, shift ) );
}


TEST( KeyTest, RemoveKeyTest )
{
    const char* key = "key";
    const char* db = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    const char* keyFileName = "keyFile";
	const char* dataBaseFile = "dataFile";
    const char* value = "value";
    const int shift = 4;
                       
	SimpleDB simpleDB( keyFileName, dataBaseFile );
    simpleDB.connect( db, user, password);
    simpleDB.create( db, user, password, shift );
    simpleDB.insert( key, value );
    ASSERT_TRUE( simpleDB.removeKey( key ) );
}

TEST( KeyTest, KeyExistsTest )
{
    const char* key = "key";
    const char* db = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    const char* keyFileName = "keyFile";
	const char* dataBaseFile = "dataFile";
    const char* value = "value";
    const int shift = 4;
            
    SimpleDB simpleDB( keyFileName, dataBaseFile );
    simpleDB.connect( db, user, password );
    simpleDB.create( db, user, password, shift );
    simpleDB.insert( key, value );
            
    ASSERT_TRUE( simpleDB.keyExists( key ) );
}
