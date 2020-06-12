#include "iostream"
/* #include "func.h" */
#include "string"
#include "Teacher.h"
using namespace std;

int main()
{
	Teacher t1; // no initializer , invoke the constructor w/o parameters
	// no need to add ()
	Teacher t2("Harvey",15);
	Teacher t3("marry");

	cout << t1.get_name() << " " << t1.get_age() << endl;
	cout << t2.get_name() << " " << t2.get_age() << endl;
	cout << t3.get_name() << " " << t3.get_age() << endl;

	// Just view a new class as the built-in type like int 
	// Allocate a unit in the memory for user-defined class object
	Teacher *p = new Teacher("Heap"); // Instantiate Teacher from the Heap
	if(p == NULL)
	{
		cout << "Allocation fails!" << endl;
		exit(0);
	}
	cout << p->get_name() << " " << p->get_age() << endl;

	delete p;
	p = NULL;

	return 0;
}
