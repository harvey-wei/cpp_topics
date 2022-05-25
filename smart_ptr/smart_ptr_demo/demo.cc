#include <iostream>
using namespace std;

// A generic smart pointer class
template <class T>
class SmartPtr {
	T* ptr; // Actual pointer
public:
	// Constructor
	explicit SmartPtr(T* p = NULL) { ptr = p; }

	// Destructor
	~SmartPtr() { delete (ptr); }

	// Overloading dereferencing operator
	T& operator*() { return *ptr; }

	// Overloading arrow operator so that
	// members of T can be accessed
	// like a pointer (useful if T represents
	// a class or struct or union type)
	T* operator->() { return ptr; }
};

int main()
{
	SmartPtr<int> ptr(new int());
	*ptr = 20;
	cout << *ptr << "\n";
	return 0;
}

/* Q: Why is there an extra percent sign after the output?
   A: Your shell (zsh) added it to indicate the output did not end with a newline character.
   ref: https://stackoverflow.com/questions/53932577/why-is-there-an-extra-percent-sign-after-the-output
*/
