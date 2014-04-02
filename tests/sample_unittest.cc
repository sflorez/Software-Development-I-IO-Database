#include <limits.h>
#include "SimpleDB.h"
#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
using namespace std;

TEST(SimpleDB, IsFileThere)
{
    
    const string &key = "KeyFile";
    const string &database = "dataFile"; 
    
    const char* keyFileName = key.c_str();
    const char* dataFileName = database.c_str();
    
    SimpleDB simpleDB( key, database );
    
    ifstream file(keyFileName);
    ifstream file2(dataFileName);     
       
    ASSERT_TRUE(file);
    ASSERT_TRUE(file2);
    
   
}
