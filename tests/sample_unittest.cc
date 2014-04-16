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


TEST( SimpleDB, RemoveKeyTest )
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

TEST( SimpleDB, KeyExistsTest )
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

TEST( SimpleDB, CloseTest )
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
    ASSERT_TRUE( simpleDB.getConnect() );
    
    simpleDB.close();
    
    ASSERT_FALSE( simpleDB.getConnect() );
}

TEST( SimpleDB, SelectTest)
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
    
    ASSERT_EQ( key, simpleDB.select( key ) );
    
}

TEST( SimpleDB, UpdateTest )
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
    
    ASSERT_TRUE( simpleDB.update( key, value ) );
}

TEST( Key, KeyGetTest)
{
    string keyName = "key";
    int pos = 1;
    int length = 3;
    Key key( keyName, pos, length );
    ASSERT_EQ( keyName, key.getKey() );
}

TEST( Key, KeySetTest)
{
    string keyName = "key";
    string keyNewName = "key2";
    int pos = 1;
    int length = 3;
    Key key( keyName, pos, length );
    key.setKey( keyNewName );
    ASSERT_EQ( keyNewName, key.getKey() ); 
}


TEST( Key, KeyGetSetPosTest )
{
    string keyName = "key";
    int pos =1;
    int length = 3;
    Key key( keyName, pos, length );
    ASSERT_EQ( pos, key.getPos() );
    
    key.setPos( 5 );
    ASSERT_EQ( 5, key.getPos() );
}

TEST( Key, KeyGetSetLenTest )
{
    string keyName = "key";
    int pos = 1;
    int length = 3;
    Key key( keyName, pos, length );
    ASSERT_EQ( length, key.getLength() );
    
    key.setLength( 5 );
    ASSERT_EQ( 5, key.getLength() );
}
 
TEST( MergeSort, MergeSortCompare )
{
   const char* key1 = "a";
   const char* key2 = "b";
   
//   mergeSort merge();
   ASSERT_EQ( -1, compareASCII( key1, key2 ) );
   
   const char* key3 = "b";
   const char* key4 = "a";
   ASSERT_EQ( 1, compareASCII( key3, key4 ) );
  
   const char* key5 = "a";
   const char* key6 = "a";
   ASSERT_EQ( 0, compareASCII( key5, key6 ) );
}

