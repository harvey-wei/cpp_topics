// C++ code to demonstrate bind() and
// placeholders
// ref: https://www.geeksforgeeks.org/bind-function-placeholders-c/
#include <iostream>
#include <functional> // for bind()
using namespace std;

// for placeholders
using namespace std::placeholders;

// Driver function to demonstrate bind()
void func(int a, int b, int c)
{
	cout << (a - b - c) << endl;
}

int main()
{
	// for placeholders
	using namespace std::placeholders;

	// Use of bind() to bind the function
	// _1 is for first parameter of function returned by bind and assigned
	// to 'a' in above declaration.
	// 2 is assigned to b
	// 3 is assigned to c
    // the first argument of std::bind is a function name or functor or function pointer
	auto fn1 = bind(func, _1, 2, 3);

	// 2 is assigned to a.
	// _1 is for first parameter and assigned
	// to 'b' in above declaration.
	// 3 is assigned to c.
	auto fn2 = bind(func, 2, _1, 3);

	// calling of modified functions
	fn1(10);
	fn2(10);

	return 0;
}
