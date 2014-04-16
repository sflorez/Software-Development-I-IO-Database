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

TEST( AllTest, ConstructorTest )
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
TEST( AllTest, CreateTest )
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

TEST( AllTest, ConnectTest )
{
    const char* db = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    const char* keyFileName = "keyFile";
    const char* dataBaseFile = "dataFile";
 
    SimpleDB simpleDB( keyFileName, dataBaseFile );
    ASSERT_FALSE( simpleDB.getConnect() );
    simpleDB.connect( db, user, password); 
    ASSERT_TRUE( simpleDB.getConnect() );
    simpleDB.close();
}


/*
 * Called the "insert" in the fixture
 */


TEST( AllTest, InsertTest )
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
    //cout << "Going into create " << endl;
    simpleDB.create( db, user, password, shift );
    //cout << "Out of create" << endl;
    ASSERT_TRUE( simpleDB.insert( key, value ) );
}


/*
 * Tests Encryption to passes with correct inputs
 */
TEST( AllTest, EncryptTest )
{
    char* data = new char[4];
    strcpy(data, "key1");
    int shift = 4;
    ASSERT_TRUE( Algorithm::encrypt( data, shift ) );
}

/*
 * Tests if encryption passes with correct inputs
 */
TEST( AllTest, DecryptTest )
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
TEST( AllTest, EncryptionAsciiBounds )
{
    char* data = new char[7];
    strcpy(data,"áBadAllTest");
    int shift = 3;
    ASSERT_FALSE( Algorithm::encrypt( data, shift ) );
}

/*
 * Tests the bounds of the ascii values are within
 * 32-126
 */
TEST( AllTest, DecryptionAsciiBounds )
{
    char* data = new char[7];
    strcpy(data, "áBadAllTest");
    int shift = 3;
    ASSERT_FALSE( Algorithm::encrypt( data, shift ) );
}

/**
TEST( AllTest, RemoveAllKeysTest )
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
*/

/**
TEST( AllTest, KeyExistsTest )
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
*/

TEST( AllTest, CloseTest )
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

TEST( AllTest, SelectTest)
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
    //simpleDB.insert( key, value );
    
    ASSERT_EQ( key, simpleDB.select( key ) );
    
}

TEST( AllTest, UpdateTest )
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

TEST( AllTest, KeyGetTest)
{
    string keyName = "key";
    int pos = 1;
    int length = 3;
    Key  key( keyName, pos, length );
    ASSERT_EQ( keyName, key.getKey() );
}

TEST( AllTest, KeySetTest)
{
    string keyName = "key";
    string keyNewName = "key2";
    int pos = 1;
    int length = 3;
    Key key( keyName, pos, length );
    key.setKey( keyNewName );
    ASSERT_EQ( keyNewName, key.getKey() ); 
}


TEST( AllTest, KeyGetSetPosTest )
{
    string keyName = "key";
    int pos =1;
    int length = 3;
    Key key( keyName, pos, length );
    ASSERT_EQ( pos, key.getPos() );
    
    key.setPos( 5 );
    ASSERT_EQ( 5, key.getPos() );
}

TEST( AllTest, KeyGetSetLenTest )
{
    string keyName = "key";
    int pos = 1;
    int length = 3;
    Key key( keyName, pos, length );
    ASSERT_EQ( length, key.getLength() );
    
    key.setLength( 5 );
    ASSERT_EQ( 5, key.getLength() );
}
 
TEST( AllTest, MergeSortCompare )
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

