#include "func.h"
#include "iostream"

using namespace std;

// It is good practice to specify the default values only in the correponding header file ".h" not in the source file ".cpp" for the puporse of successfule compilation in all kinds of c++ compilers!
void fun(int i, int j, int k)
{
	cout << i << j << k << endl;
}
