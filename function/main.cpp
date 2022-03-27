/* Learn more about the function */
/* 01.06.2019 */

#include "iostream"
using namespace std; 


inline double get_max(double x, double y);
inline int get_max(int x, int y, int z);
void fun_1(int i, int j = 5, int k = 10);
// It is better to specify the default value only in the function declaration:
// not in the function definition because some compilers will report error
int main()
{
	// default value in C++ function
	fun_1(20);
	fun_1(20,32);
	fun_1(20,30,40);
	
	// overload in C++ function
	cout <<	get_max(12,36,56) << endl;
		
}

void fun_1(int i, int j, int k)
{
	cout << i << j << j <<endl;
}

inline int get_max(int x, int y, int z)
{
	//todo
	int max(x);
	if (y > max)
	{
		max = y;
	}
	if ( z > max)
	{
		max = z;
	}
	return max;
}

inline double get_max(double x, double y)
{
	//todo 
	return x > y ? x : y;
}
