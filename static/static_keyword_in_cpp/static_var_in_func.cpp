/*
C++ program to demonstrate the use of static variable defined in function
*/

// Key point on the static within a function!
/*
 When a variable is declared as static, space for it gets allocated for the lifetime of the program. Even if the function is called multiple times, space for the static variable is allocated only once and the value of variable in the previous call gets carried through the next function call. This feature is quite helpful for those applications where the previous state of a function needs to be stored
*/
/*
From the perspective of memory space, the static object is stored in the static storage! In terms of the life time, static owns the same lifetime as the whole program!
*/
#include <iostream>
using namespace std;

int& demo()
{
	// declare a static variable
	static int counter(0);  // the counter gets initialized only once even if the demo() is invoked multiple times
	/*
	You can see in the above program that the variable count is declared as static. So, its value is carried through the function calls. The variable count is not getting initialized for every time the function is called.
	*/

	cout << "The value of static variable counter is " <<  counter << endl;

	// Value is upated and it will be carried to the next function call!
	counter ++;

    return counter;
}

int main()
{
	for(int i(1); i < 6; i++)
	{
		int & var = demo();
        std::cout << "var: " << var << std::endl;
	}

	return 0;
}
