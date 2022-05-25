// C++ program to illustrate
// default constructor with
// 'explicit' keyword
#include <iostream>
using namespace std;

class Complex {
private:
	double real;
	double imag;

public:
	// Default constructor
	explicit Complex(double r = 0.0,
					double i = 0.0) :
					real(r), imag(i)
	{
	}

	// A method to compare two
	// Complex numbers
	bool operator == (Complex rhs)
	{
		return (real == rhs.real &&
				imag == rhs.imag);
	}
};

// Driver Code
int main()
{
	// a Complex object
	Complex com1(3.0, 0.0);

	/* if (com1 == 3.0) */
    /* if (com1 == (Complex)3.0) */
    if (com1 == Complex(3.0))
		cout << "Same";
	else
		cout << "Not Same";
	return 0;
}

/** Q: Why to use explicit specifier to modify the constructor which can be called with one
  * argument?
  * A: if a class has a constructor which can be called with a single argument, then this
  * constructor becomes a conversion constructor because such a constructor allows conversion of
  * the single argument to the class being constructed.
  * We can avoid such implicit conversions as these may lead to unexpected results using explicit!
  * ref: https://www.geeksforgeeks.org/use-of-explicit-keyword-in-cpp/
  * ref: https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
  */

