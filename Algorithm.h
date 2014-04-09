/*
 * Author Antonio Garcia
 * date re created April 3rd 2014
 *
 * Algorithm for encryption and decryption
 *
 */
#ifdef ALGORITHM_H
#define ALGORITHM_H

class Algorithm
{
	private:
		Algorithm();

	public:
		 static int	add(int a, int b);

	private:

		 char encrypt(char* data, int shift);
		 char decrypt(char* data, int shift);
		 bool encrypt(char* data, int shift);
		 bool decrypt(char* data, int shift);
};

#endif
