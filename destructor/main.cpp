#include "iostream"
#include "string"
#include "class.h"
#include "func.h"
using namespace std;
//Stick to the strategy of separating declarations and implementations!!!
// for the sake of convenient sharing across source files!!!
/* If we do not write our own destructor in class, compiler creates a default destructor for us. The default destructor works fine unless we have dynamically allocated memory or pointer in class. When a class contains a pointer to memory allocated in class, we should write a destructor to release memory before the class instance is destroyed. This must be done to avoid memory leak.*/

int main()
{
	Teacher t1("Bob",12);   // instantiate from the stack!!!
	Teacher t2(t1);
	Teacher t3 = t1;
	test_func(t1); //  invoke the copy constuctor!!!! 
	// only one of the copy constuctor and constuctor will be invoked when object is created
	Teacher * p = new Teacher;  // instantiated from the heap!!!
	if (!p)
	{
		cout << "memory allocation fails" <<endl;
	}

	delete p;   // release the memory space
	p = NULL;   // avoid reuse of the already freed space !!!
	/* cout << t2.get_name() << endl; */
	/* cout << t2.get_age() << endl; */ 
	// if user defines a copy constructor, but not write code to implement
	// the initialization, the data member of newly created object will be
	// undefined!!!

	return 0;
}
