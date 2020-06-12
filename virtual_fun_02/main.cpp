#include <iostream>
#include <string>
using namespace std;
/*
   Virtual Function (member function) are invoked according to the type of object to which the pointer points or 
   to which the reference refers to!!!
   Keep it in mind that IS A, HAS A, VPTR VTABLE(polymorphism by virtual function) does not depend on ptr or ref!!!
   virtual function allow the base pointer and base reference to access the member function of derived,i.e. 
   The virtual base function is said to be overriden!!!
*/
class Base 
{
	public:
		virtual void print()
		{
			cout << "I am Base class " << endl;
		}
		
		void show()
		{
			cout << "Show Base class " << endl;
		}

};
// Only public mode of inheritance ensure the IS A and HAS A relation between base and derived!!!!
class Derived : public Base 
{
	public:
		virtual void print()    // The function with the same in Base is overridden!!!
		{
			cout << "I am Derived " << endl;
		}

		void show()
		{
			cout << "Show Derived Class " << endl;
		}
};
int main()
{
	Derived derived;
	Base &ref_Base = derived;
	Base *ptr_Base = &derived;

	ref_Base.print();
	ref_Base.show();

	ptr_Base->print();
	ptr_Base->show();

	return 0;
}
