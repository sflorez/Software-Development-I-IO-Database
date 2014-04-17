#ifdef DBEXCEPTION_H
#define DBEXCEPTION_H

class DBException
{
    private:
        const string myErrorMessage;
    public:
        userPassException(const string message = "Invalid Username or Password.") :
            myErrorMessage(message) {}
        virtual ~userPassException() {}
        const string & getErrorMessage() const {return myErrorMessage;}
// user and pass, key not existing, not connected, value bounds for update
// it shouldnt be longer than what you have had, and if there are
// two of the same database THAT SHOULD NOT HAPPEN
};


#endif
