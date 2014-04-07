#include <limits.h>
#include "SimpleDB.h"
#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
using namespace std;


/**
 * Test Fixtures
 * 
 */ 
class SimpleDBTest : public testing::Test 
{
    protected:
        
        /**
         * Helper method
         */ 
        
        void ConstructorTester( const string &keyFile, const string &dataFile )
        {
            const char* keyFileName = keyFile.c_str();
            const char* dataFileName = dataFile.c_str();
            ifstream file(keyFileName);
            ifstream file2(dataFileName);
            
            ASSERT_TRUE(file);
            ASSERT_TRUE(file2);
            
            SimpleDB::SimpleDB simpleDB( keyFile, dataFile );
            
            ASSERT_TRUE(file);
            ASSERT_TRUE(file2);
        }
};


/**
 * Uses the test fixture to test the "constructorTester"
 */
TEST_F(SimpleDBTest, isFileThere)
{
    const string &key = "keyFile";
    const string &data = "dataFile";
    ConstructorTester( key, data );   
}
