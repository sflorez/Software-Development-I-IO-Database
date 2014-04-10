
#ifndef ALGORITHM_H_
#define ALGORITHM_H_

class Algorithm {
public:
	Algorithm();
	virtual ~Algorithm();
	char* encrypt(char* data , int shift);
	char* decrypt(char* data , int shift);
	bool canEncrypt( char* data, int shift);
	bool canDecrypt( char* data, int shift);
};

#endif /* ALGORITHM_H_ */
