#include <iostream>
#include <string>
using namespace std;

class A
{
	public:
		A(int _a)
		{
			cout << "A: " << _a << endl;
		}

};

class B: public A
{
	public:
		B(int _a, int _b)
			:A(_a) // call A constructor!
		{
			cout << "B: " << _b << endl;	
		}
};

/*
It is worth mentioning that constructors can only call constructors from their immediate parent/base class. Consequently, the C constructor could not call or pass parameters to the A constructor directly. The C constructor can only call the B constructor (which has the responsibility of calling the A constructor).
However, it does not apply to the virtual base! In a virtual derivation, the virtual base is initialized by the most derived constructor!
*/

class C: public B
{
	public:
		C(int _a, int _b, int _c)
			:B(_a, _b)
		{
			cout << "C: " << _c << endl; 
		}

};

int main()
{
	C c(1, 2, 3);
	return 0;

}

/*
	
*/
