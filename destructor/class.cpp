#include "iostream"
#include "string"
#include "class.h"
using namespace std;
// Destructor has neither parameter nor return type
// Hence, overload is impossible for it!
// As usual, for the class member function defined outside the class declaration  the function name in definition must be preceded by ClassName:: 
Teacher::~Teacher()
{
	/* delete []m_char_name; // Note that [] means to release block of memory!! */
	cout << "~Teacher()" <<endl;
}
Teacher::Teacher(string _name, int _age)
{
	m_str_name = _name;
	m_int_age = _age;
	cout << "Teacher(string _name, int _age)" << endl;
}


string Teacher::get_name()
{
	return m_str_name;
}


// A copy constructor possesses the following function prototype:
// ClassName (const ClassName & old_obj) which servers the purpose of initializing 
// an object using another object of the same class!!!
// Copy constructor is one type of constructor. Hence, copy constructor also owns all features of constructor discussed above!
/*
If we do not define our own copy constructor, the C++ compiler creates a default copy constructor for each class which does a member-wise copy between objects(shawllow copy).
We need to define our own copy constuctor if an object has pointers or reference.
Shallow copy and deep copy bear the difference for pointers and reference!
By shallow copy, the pointers of the two objects point to the same memory location  whereas they point to different memory location in the case of deep copy!
Deep means new memory location!
*/
Teacher::Teacher(const Teacher &tea)
{
	cout <<"Teacher(const Teacher &tea);"<<endl;
}

int Teacher::get_age()
{
	return m_int_age;
}
