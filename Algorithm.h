#ifdef ALGORITHM_H
#define ALGORITHM_H

class Algorithm
{
	private:
		Algorithm();

	public:
		 static int	add(int a, int b);
		
	private:
		 bool encrypt(char* data, int shift);
		 bool decrypt(char* data, int shift);
		 	 
} 

#endif 
