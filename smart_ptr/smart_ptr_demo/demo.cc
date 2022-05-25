#include <iostream>
using namespace std;

// A generic smart pointer class
// RAII: Resource Acquisition Is Initialization!
template <class T>
class SmartPtr {
private:
	T* ptr; // Actual pointer

public:
	// Constructor
	explicit SmartPtr(T* p = NULL) { ptr = p; }

	// Destructor
	~SmartPtr() {
        delete (ptr);
        cout << "ptr is deleted" << std::endl;
    }

	// Overloading dereferencing operator return what is pointed by actual pointer.
    // Otherwise, dereferencing behavior is undefined!
	T& operator*() { return *ptr; }

	// Overloading arrow operator so that
	// members of T can be accessed
	// like a pointer (useful if T represents
	// a class or struct or union type). That is, smart_ptr->return the actual pointer.
    // Otherwise, arrow operator's behavior is undefined!
	T*& operator->() { return ptr; }

    /** Note that you can not overload the dot operator!
      */
};

class Point
{
    public:
        Point(int x = 0, int y = 0):
            x(x),
            y(y)
        {}

        int x;
        int y;
};

int main()
{
    /* new returns a pointer of type int * here */
	SmartPtr<int> ptr(new int());
	*ptr = 20;
	cout << *ptr << "\n";

    SmartPtr<Point> pt_ptr(new Point(1, 2));
    cout << pt_ptr->x << std::endl;

	return 0;
}

/* Q: Why is there an extra percent sign after the output?
   A: Your shell (zsh) added it to indicate the output did not end with a newline character.
   ref: https://stackoverflow.com/questions/53932577/why-is-there-an-extra-percent-sign-after-the-output

   Q: What is the reference to pointer?
   A: https://stackoverflow.com/questions/14016770/difference-between-t-and-t-c

   https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/
   Initialize memory: pointer-variable = new data-type(value);
   Allocate a block of memory: pointer-variable = new data-type[size];
*/
