#include <iostream>
#include <string>
using namespace std;
class Base 
{
	protected:
		int m_int_value;

	public:
		Base(int _value)
		{
			m_int_value = _value;
			cout << "Base()" << endl;
		}

		virtual ~Base()
		{
			cout << "~Base()" << endl; 
		}

		string get_name()
		{
			return "Base";
		}

		int get_value()
		{
			return m_int_value;
		}
};

class Derived : public Base
{
	public:
		Derived(int _value) : Base(_value)
		{
			cout << "Derived()" << endl;	
		}

		~Derived()
		{
			cout << "~Derived()" << endl;
		}

		string get_name()
		{
			return "Derived";
		}

		int get_value_doubled()
		{
			return m_int_value * 2;	
		}
};

// Due to the function hiding does not depend on the pointer or refernce!!!
// The behavior of pointer and reference are similar!!
int main()
{
	Derived derived(5);
	cout << "derived is a" << derived.get_name() << " and has value " << derived.get_value() << endl; 
	// do not forget the function call operator ()!!!

	Base &ref_Base = derived;    // C++ allow the Base reference to refer to the derived object like pointer
	Base *ptr_Base = &derived;  
	/* ref_Base.get_value_doubled();  // Like ptr, ref_Base can not access the member in derived class except the virtual member function occuring both in sub and super class!! */

	cout << "ref_Base is a" << ref_Base.get_name() << " and has value " << ref_Base.get_value() << endl; 
	cout << "ptr_Base is a" << ptr_Base->get_name() << " and has value " << ptr_Base->get_value() << endl; 
	
	return 0;
}
