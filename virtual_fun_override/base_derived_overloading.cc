// A CPP program without override keyword, here
// programmer makes a mistake and it is not caught
#include <iostream>
using namespace std;

class Base {
public:
	// user wants to override this in
	// the derived class
	virtual void func() { cout << "I am in base" << endl; }
};

class derived : public Base {
public:
	// did a silly mistake by putting
	// an argument "int a"
    // to overload the base function
	void func(int a)
	{
		cout << "I am in derived class" << endl;
	}
};

// Driver code
int main()
{
	Base b;
	derived d;
	cout << "Compiled successfully" << endl;
    d.func(10);
    /* d.func(); */

	return 0;
}

