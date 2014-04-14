#ifdef DBEXCEPTION_H
#define DBEXCEPTION_H

class DBException
{
    private:
        const string myErrorMessage;
    public:
        DBException(const string message = "Invalid entry.") :
            myErrorMessage(message) {}
        virtual ~DBException() {cout << "In Destructor\n";}
        const string & getErrorMessage() const {return myErrorMessage;}

};

#endif
