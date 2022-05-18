#include "iostream"
using namespace std;

/* void fun(int i = 30 , int j,int k = 40); report error */
/* void fun(int i= 30, int j = 40, int k); also report error */
inline void fun(int i = 30,int j= 10,int k = 30);

// overload function:
// prerequisite:1 all the function of the same fun_name must be in the same scope such as namespace
// prerequisite:2 the number of parameters or the type of parameters must be different
inline void fun(double i, double j);
// It is sufficient to prefix the declaration with inline keyword 
// No need to add inline to the definition!!!
int main()
{
	// default value in function 
	/* fun(); // because all the parameters have default values */ 
	/* fun(100); */
	/* fun(100,200); */
	/* fun(100,200,300); */
	// overload function test
	fun(1.1,2.2); // Note that 1.1 and 2.2 are resolved as floating number such double
	fun(1,2); 	 // 1 and 2 are interpreted as integer
return 0;
}

void fun(int i,int j, int k)
{
	cout << i << "," << j << "," <<k << "," << endl ;
}

void fun(double i, double j)
{
	cout << i << "," << j << "," <<  endl;	
}
