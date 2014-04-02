#include <limits.h>
#include "SimpleDB.h"
#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
using namespace std;


class SimpleDBTest : public testing::Test 
{
    protected:
        
        void ConstructorTester( const string &keyFile, const string &dataFile )
        {
            const char* keyFileName = keyFile.c_str();
            const char* dataFileName = dataFile.c_str();
            ifstream file(keyFileName);
            ifstream file2(dataFileName);
            
            ASSERT_FALSE(file);
            ASSERT_FALSE(file2);
            
            SimpleDB::SimpleDB simpleDB( keyFile, dataFile );
            
            ASSERT_TRUE(file);
            ASSERT_TRUE(file2);
        }
};


TEST_F(SimpleDBTest, isFileThere)
{
    const string &key = "keyFile";
    const string &data = "dataFile";
    ConstructorTester( key, data );   
}
