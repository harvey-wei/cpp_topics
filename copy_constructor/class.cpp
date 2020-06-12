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


string Teacher::get_name()
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
