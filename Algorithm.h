
#ifndef ALGORITHM_H_
#define ALGORITHM_H_

class Algorithm {
private:
	Algorithm();
	bool encrypt(char* data , int shift);
	char* decrypt(char* data , int shift);
	bool canEncrypt( char* data, int shift);
	bool canDecrypt( char* data, int shift);
public:
    bool getEncrypt(char* data, int shift);
    virtual ~Algorithm();
};

#endif /* ALGORITHM_H_ */
