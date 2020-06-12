#include <iostream>
#include <string>
using namespace std;

static void func();

/*
In C, functions are global by default. The “static” keyword before a function name makes it static. What is meant by global is that the function defined outside of the main function can be shared across different files!
However, Unlike global functions in C, access to static functions is restricted to the file where they are defined. Therefore, when we want to restrict access to functions, we make them static. Another reason for making functions static can be reuse of the same function name in other files.
*/
int main()
{
	func();

	return 0;
}
