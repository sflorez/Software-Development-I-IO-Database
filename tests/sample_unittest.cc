#include <limits.h>
#include <iostream>
#include <fstream>
#include "SimpleDB.h"
#include "Key.h"
#include "Algorithm.h"
#include "gtest/gtest.h"
#include "Algorithm.cpp"
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
        
        /*
         * 
         * @params: db, user, password
         */
        
        void connectTest( const char* db, const char* user, const char* password )
        {
            i_KeyFileName = "keyFile";
            i_DatabaseFile = "dataFile";
                           
            SimpleDB simpleDB( i_KeyFileName, i_DatabaseFile );
            simpleDB.connect( db, user, password);
            ASSERT_FALSE(simpleDB.getConnect());
            
            simpleDB.connect( db, user, password);
            
            ASSERT_TRUE(simpleDB.getConnect());
        }
        /*
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
            SimpleDB simpleDB( i_KeyFileName, i_DatabaseFile );
            simpleDB.connect( i_db, i_user, i_password);
            simpleDB.create( i_db, i_user, i_password, shift );
            ASSERT_TRUE(simpleDB.insert( key, value ));
        }
        
       
        void EncryptTest( char * data , int shift )
        {
            ASSERT_TRUE( Algorithm::encrypt( data, shift ) );
        }
        
        void DecryptTest( char* data , int shift )
        {
            ASSERT_TRUE( Algorithm::decrypt( data, shift) );
        }
        void EncryptionAsciiBounds(char* data, int shift)
        {
            ASSERT_FALSE(Algorithm::encrypt(data, shift));
        }
         void DecryptionAsciiBounds(char* data, int shift)
        {
            ASSERT_FALSE(Algorithm::encrypt(data, shift));
        }
};


/*
 * Uses the test fixture to test the "constructorTester"
 * Using the _F alerts it to use the fixture.
 */
TEST_F(allTest, ConstructorTest)
{
    const string &key = "keyFile";
    const string &data = "dataFile";
    ConstructorTester( key, data );
}

/*
 * Calls the "connectTest"
 */
TEST_F(allTest, connectTest)
{
    const char* db = "TestDataBase";
    const char* user = "TestUserName";
    const char* password = "TestPassword";
    connectTest( db, user, password );
}


/*
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

/*
 * Called the "insert" in the fixture
 */

TEST_F(allTest, InsertTest)
{
    const char* key = "key";
    const char* value = "value";
    InsertTest( key, value) ;
}

/*
 * Tests Encryption to passes with correct inputs
 */
TEST_F(allTest, EncryptTest)
{
    char* key = new char[4];
    strcpy(key, "key1");
    int shift = 4;
    EncryptTest( key, shift );
}

/*
 * Tests if encryption passes with correct inputs
 */
TEST_F(allTest, DecryptTest)
{
    char* key = new char[4];
    strcpy(key, "key1");
    int shift = 4;
    DecryptTest( key, shift );
}

/*
 * Tests the bounds of the ascii values are within
 * 32-126
 */
TEST_F(allTest, EncryptionAsciiBounds)
{
    char* key = new char[7];
    strcpy(key,"áBadKey");
    int shift = 3;
    EncryptionAsciiBounds(key, shift);
}

/*
 * Tests the bounds of the ascii values are within
 * 32-126
 */
TEST_F(allTest, DecryptionAsciiBounds)
{
    char* key = new char[7];
    strcpy(key, "áBadKey");
    int shift = 3;
    DecryptionAsciiBounds(key, shift);
}

/*
 * Tests Merge Sorting
 */
TEST_F(allTest, mergeSortTest)
{
    :vector<Key*> keys;
    string name1 = "zergRush";
    string name2 = "Antonio";
    string name3 = "Sebastian";
    string name4 = "Christian";
    
    for(unsigned int i = 1; i < 5; i++)
    {
        keys.push_back(new Key(name+(string)i,1,1))
    }
    for(unsigned int i = 0;i<4;i++)
    {
        cout << keys[i]->getKey() << endl;
    }
    
}
#include<string>
#include<cstring>
#include <iostream>
#include "mergeSort.h"
#include "Key.h"
#include <vector>
using namespace std;

vector <Key*> keys;
int main()
{
    string name = "name1thelongest";
    string name2 = "sebastian";
    string name3 = "Anton";
    string name4 = "bleh";
    string name5 = "bob";
    
    keys.push_back(new Key(name ,1,1)); 
    keys.push_back(new Key(name2 ,1,1));
    keys.push_back(new Key(name3 ,1,1));
    keys.push_back(new Key(name4 ,1,1));
    keys.push_back(new Key(name5 ,1,1));
    
    cout<< "B4 merge"<< endl;
   
    for(unsigned int i = 0; i < 5; i++ )
    {
        cout << keys[i]->getKey()<<endl;
    }        
    
    vector<Key*> temp = keys;
    int num = keys.size();
    mergeSort(keys,temp,0,num-1);
    cout<< "After merge"<<endl;
    
    for(unsigned int i = 0; i < 5; i++ )
    {
        cout << keys[i]->getKey()<<endl;
    }        
    string inputName;
    cout<< "binary search enter a name to find: "<< endl;
    cin>> inputName;
    cout << inputName << endl;
   
    if(binarySearch(keys, inputName.c_str()) < 0)
    {
        cout << "Noooope" << endl;
    }
    else
    {
         cout << keys[binarySearch(keys, inputName.c_str())]->getKey() << endl; 
    }
