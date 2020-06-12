#include "Teacher.h"
#include "iostream"
#include "string"   // string class in CPP with similar syntax to Python String
using namespace std;


void Teacher::set_name(string _name)
{
	m_str_name = _name;
}

string Teacher::get_name()
{
	return m_str_name;
}

void Teacher::set_age(int _age)
{
	m_int_age = _age;	
}
 
int Teacher::get_age()
{
	return m_int_age;
}
// Reference at https://www.geeksforgeeks.org/constructors-c/
// constructor has no return type and neither does deconstructor!
// constructor  must have the same function name 
// as Class Name 
// constructor  will be invoked automatically
// when the Class is instantiated as a object!!!
// Overload and default value can also be applied to constructor 
// cout is used to indicate this behavior explicitly
// If we do not specify a constructor, C++ compiler generates a default constructor for us (expects no parameters and has an empty body)
// Overleaded constructors 
Teacher::Teacher()
{
	m_str_name = "Jim";
	m_int_age = 29;
	cout << "Teacher()" << endl; 
}

/* Teacher::Teacher(string _name, int _age = 20)  // default must start from the end of the parameter list!!!! */
Teacher::Teacher(string _name, int _age)
{
	m_str_name = _name; 
	m_int_age = _age;
	cout << "Teacher::Teacher(string _name, int _age)" << endl;
}

