/*
Just like the static data members or static variables inside the class, static member functions also does not depend on object of class. We are allowed to invoke a static member function using the object and the ‘.’ operator but it is recommended to invoke the static members using the class name and the scope resolution operator. In an analogous vein, it is recommended to reference the static variable in class with the class name followed by the scope resolution operator :: 
*/


/*j
Static member functions are allowed to access only the static data members or other static member functions, they can not access the non-static data members or member functions of the class. In constrast, Non-static member functions can access all data members of the class: static and non-static.

The reason for that is quite obvious from the perspecive of the lifetime of the static and non-statc objects!!!Long-living static members can not access the short-liviing and perhaps un-existing objects!
(Static member functions can only operate on the static data members.)

Non-static member function has an implicit parameter this pointer whereas static member function owns on this pointer!!!! Recall this pointer points to current class object instance!!!!
*/


/*
 C++ program to demonstrate the use of the static member function in a class!
*/

#include <iostream>
using namespace std;

class Kitty 
{
	public:
		// static member function!!
		static void print_msg()
		{
			cout << "Welcome to the world of Kitty!" << endl;
		}
};

int main()
{
	// Just like static data member inside the class, the static member function is also independent of the object of the class!

	// Analogous to the reference to static variable in class, it is strongly recommended to invoke the static member function using the class name followed by the scope resolution operator ::!!!!!!
	Kitty::print_msg();

	return 0;
}
