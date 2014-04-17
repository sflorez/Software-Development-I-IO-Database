/*
 * User will enter a name for the database if not created
 * if the database is created it will ask the user
 * to open a database or create a new one
 * when selected the user will need to enter the name of
 * the database if not it will throw an exception
 * the user will enter a username and password
 * exceptions will be thrown if either are in correct
 * They will then be given several options
 * The user can insert, select,update, check if a key exists, and remove a key
 * it will then return what they want otherwise throw an exception error
 */
#include <iostream>
#include "DBException.h"
#include "SimpleDB.h"
#include <string>
using namespace std;

int main()
{
        const string &key = "keyFile";
        const string &database = "DataFile";
        const char* dataBaseName;
        const char* searchFor;
        const char* dataBaseUser;
        const char* dataBasePass;
        const char* keyName;
        const char* value;
        const char* dataKey;
        string tempUpdateKey, tempUpdateValue, tempdataKey;
        const char* updateKey;
        string erase;
        const char* toErase;
        const char* updateValue;
        string tempKeyName, tempValueName;
        string tempName, tempUser, tempPass;
        string search = "";
        int shift;
        int userChoice = 0;
        int DBC = 0; // data base choice number
        bool DBCheck = true;

        SimpleDB simpleDB(key,database);
        cout << "\nTo create a database press 1, to open an old database press 2\n" << endl;
        cin >> DBC;

        if(DBC == 1)
        {
            cout << "\nEnter the name of your new data base.\n" << endl;

            cin >> tempName; cout << "\nEnter a user name to access the same database for the future.\n" << endl;
            cin >> tempUser;
            cout << "\nEnter a password to go with that username\n" << endl;
            cin >> tempPass;
            cout << "\nEnter a shift for the encryption\n" << endl;
            cin >> shift;
            dataBaseName = tempName.c_str();
            dataBaseUser = tempUser.c_str();
            dataBasePass = tempPass.c_str();
             try
            {
                simpleDB.create(dataBaseName, dataBaseUser, dataBasePass, shift);
            }
            catch( const DBException & e)
            {
            	cout << e.getErrorMessage() << endl;
                DBCheck = false;
            }

            simpleDB.connect(dataBaseName, dataBaseUser, dataBasePass);

        }

        else if(DBC == 2)
        {
            cout << "\nEnter the database to access.\n" << endl;
            cin >> tempName;
            cout << "\nEnter the username for this database.\n" << endl;
            cin >> tempUser;
            cout << "\nEnter the password that goes with it.\n" << endl;
            cin >> tempPass;
            dataBaseName = tempName.c_str();
            dataBaseUser = tempUser.c_str();
            dataBasePass = tempPass.c_str();
            try
            {
            	simpleDB.connect(dataBaseName, dataBaseUser, dataBasePass);
            }
            catch( const DBException & e)
            {
            	cout << e.getErrorMessage() << endl;
                DBCheck = false;
            }


        }

        else
        {
            cout << "\nInvalid Entry, Bye!\n" <<endl;
            return 0;
        }
       if(DBCheck)
       {
       do
       {
            cout << "\nChoose the following inputs for it's outcome\n"
            "1: To check if a key exists."
            "\n2: To select data from a key."
            "\n3: To update the data."
            "\n4: To insert new data."
            "\n5: To remove data."
            "\n6: To Exit Database to open or create another."
            "\n7: To end the program." << endl;
            cin >> userChoice;
          switch(userChoice)
            {
                case 1:
                    cout<< "\ncase 1 if key exists\n";
                    cin >> search;
                    searchFor = search.c_str();
                    if(simpleDB.keyExists(searchFor))
                    {
                        cout << "\nThat key exists\n" << endl;
                    }
                    else
                    {
                        cout << "\nThat key does not exists\n" << endl;
                    }
                    break;
                case 2:
                    cout<< "\ncase 2 to select a key to be located\n";
                    cin >> tempdataKey;
                    dataKey = tempdataKey.c_str();
                    cout << simpleDB.select(dataKey) << endl;
                    break;
                case 3:
                    cout<< "\ncase 3 enter key and value to update\n";
                    cin >> tempUpdateKey >> tempUpdateValue;
                    updateKey = tempUpdateKey.c_str();
                    updateValue = tempUpdateValue.c_str();
                    if(simpleDB.update(updateKey, updateValue) == false)
                    {
                        cout << "\nNot Updated\n" << endl;
                    }
                    else
                    {
                        cout << "\nUpdated\n" << endl;
                    }
                    break;
                case 4:
                    cout<< "\ncase 4 to insert a key and a value for the database\n";
                    cin >> tempKeyName >> tempValueName;
                    keyName = tempKeyName.c_str();
                    value = tempValueName.c_str();
                    simpleDB.insert(keyName, value);
                    break;
                case 5:
                    cout<< "\ncase 5 to remove data\n";
                    cin >> erase;toErase = erase.c_str();
                    if(simpleDB.removeKey(toErase))
                    {
                        cout << "\nKey Removed\n" << endl;
                    }
                    else
                    {
                        cout << "\nNot removed\n" << endl;
                    }
                    break;
                case 6:
                    simpleDB.close();
                    cout << "\nTo create a database press 1, to open an old database press 2\n" << endl;
                    cin >> DBC;

                     if(DBC == 1)
                     {
                        cout << "\nEnter the name of your new data base.\n" << endl;
                        cin >> tempName;
                        cout << "\nEnter a user name to access the same database for the future.\n" << endl;
                        cin >> tempUser;
                        cout << "\nEnter a password to go with that username\n" << endl;
                        cin >> tempPass;
                        cout << "\nEnter a shift for the encryption\n" << endl;
                        cin >> shift;
                        dataBaseName = tempName.c_str();
                        dataBaseUser = tempUser.c_str();
                        dataBasePass = tempPass.c_str();
                        simpleDB.create(dataBaseName, dataBaseUser, dataBasePass, shift);
                     }

                     else if(DBC == 2)
                     {
                         cout << "\nEnter the database to access.\n" << endl;
                         cin >> tempName;
                         cout << "\nEnter the username for this database.\n" << endl;
                         cin >> tempUser;
                         cout << "\nEnter the password that goes with it.\n" << endl;
                         cin >> tempPass;
                         dataBaseName = tempName.c_str();
                         dataBaseUser = tempUser.c_str();
                         dataBasePass = tempPass.c_str();
                         simpleDB.connect(dataBaseName, dataBaseUser, dataBasePass);
                     }
                    break;
                case 7:
                    cout << "\nBye!\n\n";
            }
        }while(userChoice != 7);
        }
       return 0;
}
