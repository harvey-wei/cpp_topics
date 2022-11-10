#include <iostream>
#include <string>
using namespace std;

int static_int;  // not the static_int defined in func.cpp

/* static void func(); */
/*
In C, functions are global by default. The “static” keyword before a function name makes it static.
What is meant by global is that the function defined outside of the main function can be shared
across different files!
However, Unlike global functions in C, access to static functions is restricted to the file where
they are defined. Therefore, when we want to restrict access to functions, we make them static.
Another reason for making functions static can be reuse of the same function name in other files.

*/
int main()
{
	/* func(); */
    std::cout << static_int << std::endl;
	return 0;
}

/*
   1. Outside of the class, both static variable and static function can not be shared! That is,
   static variable and static function outside of the class has internal linkage.
   2. static variable inside and outside of the class can be initialized only once!
   Singleton Pattern uses this.
*/
