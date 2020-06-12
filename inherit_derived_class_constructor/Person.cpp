#include "Person.h"


// default values are specified only in the declaration within the .h files!!!!
// initalizer list are specified in the implementation only!!!!
Person::Person(const string & _name, int _age)
	:m_str_name(_name), m_int_age(_age)
{
	cout << "Person" << endl;
}

const string & Person::get_name() const
{
	return m_str_name;	
}



