
#ifndef ALGORITHM_H_
#define ALGORITHM_H_

class Algorithm {
private:
	Algorithm();

	char* decrypt(char* data , int shift);
	bool canEncrypt( char* data, int shift);
	bool canDecrypt( char* data, int shift);
	static const int ASCII_MAX = 126;
	static const int ASCII_MIN = 32;
	static const int BASE_SHIFT = 1;
public:
	static bool encrypt(char* data , int shift);
    virtual ~Algorithm();
};

#endif /* ALGORITHM_H_ */
