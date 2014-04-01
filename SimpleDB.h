/**
 *
 * SimpleDB: Simple Data Base Management
 *
 */

#ifndef SIMPLEDB_H
#define SIMPLEDB_H

class SimpleDB
{
    public:
        /**
         * Minimum and maximum length of key and value strings,
         * including '\0' terminator.
         */
        static const int MIN_KEY_LENGTH = 2;
        static const int MAX_KEY_LENGTH = 1024;
        static const int MIN_VALUE_LENGTH = 2;
        static const int MAX_VALUE_LENGTH = (32*1024);

        /**
         * Constructor to create (if the files do not exist) or use
         * (if they do) the database key and data files.
         */
        SimpleDB(const string &keyFile, const string &dataFile);

        /**
         * Destructor to destroy any pointer memory allocated
         * in this class.
         */
        virtual ~SimpleDB();

        /**
         * Create new database with given database name, user name,
         * and password required to open and use the database. Note
         * that this does not connect to the database, which must be
         * done separately using connect().
         *
         * Throws a DBException with proper message when fails.
         * The failed error number and message may be accessed using
         * errorNum() and errorMessage() thereafter.
         */
        void create(const char* db, const char* user, const char* password);

        /**
         * Connect to existing database with given name and credentials.
         *
         * Throws a DBException with proper message when fails.
         * The failed error number and message may be accessed using
         * errorNum() and errorMessage() thereafter.
         */
        void connect(const char* db, const char* user, const char* password);

        /**
         * Synchronize memory data to disk, storing all changes in database
         * (if any).  Useful in storing key file and cleaning up database
         * structure.
         *
         * Throws a DBException with proper message when fails.
         * The failed error number and message may be accessed using
         * errorNum() and errorMessage() thereafter.
         */
        void synchronize();

        /**
         * Synchoronize the data in memory with the database and close it.
         *
         * Calls synchronize().
         *
         * Throws a DBException with proper message when fails.
         * The failed error number and message may be accessed using
         * errorNum() and errorMessage() thereafter.
         */
        void close();

        /**
         * Code to return the error code for the last failed
         * database operation.
         *
         * @return error code.
         *
         */
        int errorNum();

        /**
         * Code to return the error message of the last failed
         * database operation.
         *
         * @return error code.
         *
         */
        const string & errorMessage();

        /**
         * Key access to determine if the entered key exists for
         * the database presently opened, if one is in fact open.
         *
         * The failed error number and message may be accessed using
         * errorNum() and errorMessage() thereafter.
         *
         * @return true or false
         */
        bool keyExists(const char *key);

        /**
         * Select data associated with given key in database.
         *
         * The failed error number and message may be accessed using
         * errorNum() and errorMessage() thereafter.
         *
         * @return pointer to data returned if found, null otherwise.
         */
        const char* select(const char *key);

        /**
         * Update value associated with given key in database
         * to given value.
         *
         * The failed error number and message may be accessed using
         * errorNum() and errorMessage() thereafter.
         *
         * @return true for success, false for failure.
         *
         */
        bool update(const char *key, const char *value);

        /**
         * Insert given key and value into database as a new
         * association.
         *
         * The failed error number and message may be accessed using
         * errorNum() and errorMessage() thereafter.
         *
         * @return true for success, false for failure.
         *
         */
        bool insert(const char *key, const char *value);

        /**
         * Remove given key and associated value from database.
         *
         * The failed error number and message may be accessed using
         * errorNum() and errorMessage() thereafter.
         *
         * @return true for success, false for failure.
         */
        bool remove(const char *key);
};

#endif
