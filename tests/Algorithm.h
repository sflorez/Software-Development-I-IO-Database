
#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include<cstring>
#include<string>
#include<iostream>

class Algorithm {
private:
	Algorithm();

    // Limit for data characters by ascii values
	static const int ASCII_MAX = 126;
	static const int ASCII_MIN = 32;
    
    // If shift is entered under 1 it will be set to 1
	static const int BASE_SHIFT = 1;
public:
    
	static bool decrypt(char* data, int shift);
    static bool encrypt(char* data, int shift);
    virtual ~Algorithm();
};

#endif /* ALGORITHM_H_ */
