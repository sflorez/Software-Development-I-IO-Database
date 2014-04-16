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
 * Tests the SimpleDB constructor to make sure that it creates the files
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
 * Tests the create function, to see if creating a new database works.
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
 * Attempts to connect to the database after it has been declared
 * If it works, will return true; else false
 */

TEST( AllTest, ConnectTest )
{
    const char* db = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    const char* keyFileName = "keyFile";
    const char* dataBaseFile = "dataFile";
    const int shift = 4;
 
    SimpleDB simpleDB( keyFileName, dataBaseFile );
    
    simpleDB.create( db, user, password, shift );
    ASSERT_FALSE( simpleDB.getConnect() );
    simpleDB.connect( db, user, password); 
    ASSERT_TRUE( simpleDB.getConnect() );
    simpleDB.close();
}


/*
 * Tests to make sure the insert function
 * Inserted something into the file
 */
TEST( AllTest, InsertTest )
{
    const char* key = "This is a key";
    const char* value = "value";
   	const char* db = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    const char* keyFileName = "keyFile";
	const char* dataBaseFile = "dataFile";
	
    const int shift = 4;
    SimpleDB simpleDB( keyFileName, dataBaseFile );
    simpleDB.create( db, user, password, shift );
    simpleDB.connect( db, user, password);
    ASSERT_TRUE( simpleDB.insert( key, value ) );
    simpleDB.close();
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
 * Attemps to remove the key that was just inserted into
 * the code
 */
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
    simpleDB.close();
}

/**
 * Makes sure the key that was just created,
 * is in the SimpleDB
 */
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
    simpleDB.close();
}

/**
 * Makes sure the file is closed and you
 * are disconnected from the database
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

/**
 * Checks if you can select the key that was just entered
 */
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
    simpleDB.insert( key, value );
    
    ASSERT_EQ( key, simpleDB.select( key ) );
    simpleDB.close();
    
}

/**
 * Attemps to update the key that was just entered
 */
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
            
    const char* keyTest = "keyTest";
    const char* valueTest = "valueTest";
    SimpleDB simpleDB( keyFileName, dataBaseFile );
    simpleDB.connect( db, user, password );
    simpleDB.create( db, user, password, shift );
    
    ASSERT_TRUE( simpleDB.update( keyTest, valueTest ) );
    simpleDB.close();
}

/**
 * Checks that error message of the test
 */
TEST( AllTest, errorMessageTest )
{
    const char* keyFileName = "keyFile";
    const char* dataBaseFile = "dataFile";
    string message = "Invalid string input?"; 
    SimpleDB simpleDB( keyFileName, dataBaseFile );
    ASSERT_EQ( message, simpleDB.errorMessage() );
}
  

/**
 * Checks the getKey function in the key.cpp
 * by inserting a new key, and getting it.
 */
TEST( AllTest, KeyGetTest)
{
    string keyName = "key";
    int pos = 1;
    int length = 3;
    Key key( keyName, pos, length );
    ASSERT_EQ( keyName, key.getKey() );
}


/**
 * Checks if the key really set,
 * by calling the get
 */
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


/**
 * Checks the key get and set postition functions
 * in the key.cpp
 */
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

/**
 * Checks the key get and set length functions
 * in the key.cpp
 */
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
 
/**
 * Checks the mergesortcompare by ASCII function
 * in merge sort
 */
TEST( AllTest, MergeSortCompare )
{
   const char* key1 = "a";
   const char* key2 = "b";
   ASSERT_EQ( -1, compareASCII( key1, key2 ) );
   
   const char* key3 = "b";
   const char* key4 = "a";
   ASSERT_EQ( 1, compareASCII( key3, key4 ) );
  
   const char* key5 = "a";
   const char* key6 = "a";
   ASSERT_EQ( 0, compareASCII( key5, key6 ) );
}

 

