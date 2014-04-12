#include "Algorithm.h"
using namespace std;

class AlgorithmTest
{

    protected:
        
       void EncryptTest( char * data , int shift )
       {
            ASSERT_TRUE( Algorithm::encrypt( data, shift ) );
       }
       
       
};
                   

TEST_F(AlgorithmTest, EncrypTest)
{
   char * data = "H";
   int shift = 4;
   EncryptTest( data, shift);
}
