
#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <iostream>
#include <string>
#include <cstring>

class Algorithm {
private:
	Algorithm();
	static const int ASCII_MAX = 126;
	static const int ASCII_MIN = 32;
	static const int BASE_SHIFT = 1;
public:
	static bool encrypt(char* data , int shift);
//	bool decrypt(char* data , int shift);
    virtual ~Algorithm();
};

#endif /* ALGORITHM_H_ */
