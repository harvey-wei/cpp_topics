#include "main.h"

int main()
{
	Shape shape;
	cout << sizeof(shape) << endl;
	// When class has no data member, C++ will give one unit to label the object
	// When class has data member, C++ will not give the extra one unit

	int *p = (int*)&shape;
	cout << p << endl;

	Circle circle(100);
	int *q = (int*)&circle;  // when virtual, this the address of VTABLE
	cout << q << endl;
	cout << (unsigned int)*q << endl;
	cout << sizeof(circle) << endl;
	q++;
	q++;
	cout << (unsigned int)*q << endl;
// recall all objects share the same copy of member function
// data member belonngs to their own
	return 0;
}
