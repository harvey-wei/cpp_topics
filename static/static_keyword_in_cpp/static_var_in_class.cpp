/*
Static variables in a class: As the variables declared as static are initialized only once as they are allocated space in separate static storage so, the static variables in a class are shared by the objects. There can not be multiple copies of same static variables for different objects. Also because of this reason static variables can not be initialized using constructors. Static variables in C++ are similar to class variables in Python! Both of them are independent of any particular object of the class and there is only one single copy  of the static variable(class variable)
*/

/*
   Static Object - Summary
Persistence: it remains in memory until the end of the program.
File scope: it can be seen only withing a file where it's defined.
Visibility: if it is defined within a function/block, it's scope is limited to the function/block. It cannot be accessed outside of the function/block.
Class: static members exist as members of the class rather than as an instance in each object of the class. So, this keyword is not available in a static member function. Such functions may access only static data members. There is only a single instance of each static data member for the entire class:
A static data member : class variable
A non-static data member : instance variable
Static member function: it can only access static member data, or other static member functions while non-static member functions can access all data members of the class: static and non-static.
*/
// C++ program to demonstrate the use of the static variable within/inside the class, namely static data member similar to class variable in Python!!!

#include <iostream>
using namespace std;

class StaVar
{
	public:
		static int i; // no initialization

		StaVar()
		{
			// do nothing!
		}

};

int StaVar::i = 1; // a static variable inside a class should be initialized explicitly by the user using the class name and scope resolution operator outside the class. This pattern is similar to the split of function declaration and defintion!!! But we can not put the initialization within the class!!!

int main()
{
	// the wrong use of the static variable inside of the class
	/* StaVar obj1, obj2; */
	/* obj1.i = 2; */
	/* obj2.i = 3; */

	// print the value of i
	/* cout << obj1.i << " " << obj2.i << endl; */
	StaVar::i ++;
	// ClassName:: Static variable name can access the static data member!!!

	cout << StaVar::i << endl;

	return 0;
}
