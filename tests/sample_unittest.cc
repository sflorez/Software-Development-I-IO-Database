#include <limits.h>
#include <iostream>
#include <fstream>
#include "SimpleDB.h"
#include "Key.h"
#include "Algorithm.h"
#include "gtest/gtest.h"
using namespace std;


/**
 * Test Fixtures 
 */ 

class allTest : public testing::Test 
{
    protected:
        const char* i_DatabaseFile;
        const char* i_KeyFileName;
        const char* i_db;
        const char* i_user;
        const char* i_password;
        
        /**
         * Has the constructor create two files, keyFile and dataFile,
         * then tests if they are there
         * 
         * @params: keyFile and dataFile
         */  
        void ConstructorTester( const string &keyFile, const string &dataFile )
        {
            const char* keyFileName = keyFile.c_str();
            const char* dataFileName = dataFile.c_str();
            SimpleDB simpleDB( keyFileName, dataFileName );
            ifstream file(keyFileName);
            ifstream file1(dataFileName);
  
            ASSERT_TRUE(file);
            ASSERT_TRUE(file1);
        }
        
        /**
         * 
         * 
         * @params: db, user, password, shift
         */ 
        void CreateTest( const char* db, const char* user, const char* password, const int shift )
        { 
            i_KeyFileName = "keyFile";
            i_DatabaseFile = "dataFile";
            SimpleDB simpleDB(i_KeyFileName, i_DatabaseFile);
            simpleDB.create( db, user, password, shift );
                   
            string correct = "TestDataBase TestUserName TestPassword 4"; 
                        
            string buffer;
            ifstream file;
            file.open(i_KeyFileName, ios::in);
            getline(file, buffer);
            
            ASSERT_EQ(correct, buffer);             
        }
        
        /**
         * 
         * 
         * @params: key, value 
         */ 
        void InsertTest( const char* key , const char* value )
        {
            i_KeyFileName = "keyFile";
            i_DatabaseFile = "dataFile";
            i_db = "TestDataBase";
            i_user = "TestUserName";
            i_password = "TestPassword";
            const int shift = 4;
            SimpleDB simpleDB( i_KeyFileName, i_DatabaseFile);
            simpleDB.create(i_db, i_user, i_password, shift);            
            ASSERT_TRUE(simpleDB.insert( key, value ));                                           
        }
        
        void EncryptTest( char * data , int shift )
        {
            Algorithm algorithm();
                        
            ASSERT_TRUE( algorithm.encrypt( data, shift ) );
        }
};


/**
 * Uses the test fixture to test the "constructorTester"
 * Using the _F alerts it to use the fixture.
 */
TEST_F(allTest, ConstructorTest)
{
    const string &key = "keyFile";
    const string &data = "dataFile";
    ConstructorTester( key, data );   
}

/**
 * Calls the "CreateTest" in the fixture
 */


TEST_F(allTest, CreateTest)
{
    const char* dataBase = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    const int shift = 4;
    CreateTest( dataBase, user, password, shift);
}

/**
 * Called the "insert" in the fixture
 *//

TEST_F(allTest, InsertTest)
{
    const char* key = "key";
    const char* value = "value";
    InsertTest( key, value) ;
}

TEST_F(allTest, EncryptTest)
{
    char * key = "key1";
    int shift = 4;
    EncryptTest( key, shift );
}
