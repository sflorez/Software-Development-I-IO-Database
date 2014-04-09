#include <limits.h>
#include "SimpleDB.h"
#include "Key.h"
#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
using namespace std;


/**
 * Test Fixtures 
 */ 
class SimpleDBTest : public testing::Test 
{
    protected:
        
        const char* i_DatabaseFile = "dataFile";
        const char* i_KeyFileName = "keyFile";
        const char* i_db = "TestDataBase";
        const char* i_user = "TestUserName";
        const char* i_password = "TestPassword";
        const int i_shift = 4;        
        
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
            SimpleDB simpleDB(i_KeyFilename, i_DatabaseFile);
            simpleDB.create( db, user, password, shift );
                   
            string correct = "TestDataBase TestUserName TestPassword 4"; 
                        
            string buffer;
            ifstream file;
            file.open(keyFile, ios::in);
            getline(file, buffer);
            
            ASSERT_EQ(correct, buffer);             
        }
        
        /**
         * 
         * 
         * @params: db, user, password
         */ 
        //void ConnectTest(const char* db, const char* user, const char* password)
        //{
           
       //}
       //
        void InsertTest( const char* key , const char* value )
        {
            SimpleDB simpleDB( i_KeyFileName, i_DatabaseFile);
            simpleDB.create(i_db, i_user, i_password, i_shift);            
            ASSERT_TRUE(simpleDB.insert( key, value ));                                           
        }
};


/**
 * Uses the test fixture to test the "constructorTester"
 * Using the _F alerts it to use the fixture.
 */
TEST_F(SimpleDBTest, ConstructorTest)
{
    const string &key = "keyFile";
    const string &data = "dataFile";
    ConstructorTester( key, data );   
}

/**
 * Calls the "CreateTest" in the fixture
 */


TEST_F(SimpleDBTest, CreateTest)
{
    const char* dataBase = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    const in shift = 4;
    CreateTest( dataBase, user, password, shift);
}

/**
 * Callsed the "ConnectTest" in the fixture
 */

/**
TEST_F(SimpleDBTest, ConnectTest)
{
    const string &db = "Database";
    const string &userName = "TestUserName";
    const string &passwordName = "TestPassword";
    
    const char* dataBase = db.c_str(); 
    const char* user = userName.c_str();
    const char* password = passwordName.c_str();
}
*/

TEST_F(SimpleDBTest, InsertTest)
{
    const char* key = "key";
    const char* value = "value";
    InsertTest( key, value) ;
}
