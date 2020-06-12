#include <iostream>
#include <string>
using namespace std;

/***
Functio Template
Purpose: swap the values of two variables!! swap two numbers
***/

template <typename T>  // just view T as a class name!!!!
void swap_num(T & a, T & b)  // or pointers!!!
{
	T temp(a);
	a = b;
	b = temp;
}


int main()
{
	/* int x(10); */
	/* int y(20); */
	string x("I am ");
	string y("Harvey!");

	swap_num<string>(x, y);

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	return 0;
}
