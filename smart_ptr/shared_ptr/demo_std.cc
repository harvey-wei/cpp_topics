// C++ program to demonstrate shared_ptr
#include <iostream>
#include <memory>
using namespace std;

class A {
public:
	void show()
	{
		cout << "A::show()" << endl;
	}
    ~A(){ cout << "destroyed" << endl;}
};

int main()
{
	shared_ptr<A> p1(new A);
	cout << p1.get() << endl;
	p1->show();
	shared_ptr<A> p2(p1);
	p2->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;

	// Returns the number of shared_ptr objects
	// referring to the same managed object.
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;

	// Relinquishes ownership of p1 on the object
	// and pointer becomes NULL
	p1.reset();
	cout << p1.get() << endl;
	cout << p2.use_count() << endl;
	cout << p2.get() << endl;

	return 0;
}

/** Q: When to use shared_ptr?
  * A: Use shared_ptr if you want to share ownership of a resource.
  * Many shared_ptr can point to a single resource. shared_ptr maintains reference count
  * for this propose. when all shared_ptr pointers pointing to resource goes out of scope the resource
  * is destroyed.
  * The reference counter increments each time the 
  * ref: https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-170
  * ref: https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/
  */
