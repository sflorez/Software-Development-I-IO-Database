#ifndef ALGORITHM_H
#define ALGORITHM_H

class Algorithm
{
	private:
		Algorithm()
	private:
		bool encrypt(char* data, int shift);
	private:
		bool decrypt(char* data, int shift);

	public:
		static int add(int a, int b);
	public:
	virtual ~Algorithm();
	

};

#endif
