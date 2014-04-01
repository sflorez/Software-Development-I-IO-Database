#include<iostream>
#include "SimpleDB.h"
// testing commits from eclipse

int main()
{
    const std::string key = "keyFile";
    const std::string database = "DatabaseFile";
    
    SimpleDB simpleDB(& key, & database);
    return 0;
}


