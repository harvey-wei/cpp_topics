#include "iostream"
#include "string"
#include "class.h"
using namespace std;

Teacher::Teacher(string _name, int _age)
{
	m_str_name = _name;
	m_int_age = _age;
	cout << "Teacher(string _name, int _age)" << endl;
}


string
Teacher::get_name()
{
	return m_str_name;
}

Teacher::Teacher(const Teacher &tea)
{
	cout <<"Teacher(const Teacher &tea);"<<endl;
}

int Teacher::get_age()
{
	return m_int_age;
}


/** Q: When is the copy constructor called?
  * A: return an object of the class by value in a function
  *    pass an object of the class to a function by value
  *    Point p2 = p1; // Copy constructor is called here
  *    When the compiler generates a temporary object as the pushback of std::vector does
  */

/** Q: Why argument to a copy constructor must be passed as a reference?
  * A: Passing an object to copy constructor leads to the call to the copy constructor itself.
  * which becomes a non-terminating chain of calls.
  */

/** ref: https://www.geeksforgeeks.org/copy-constructor-in-cpp/
  */
