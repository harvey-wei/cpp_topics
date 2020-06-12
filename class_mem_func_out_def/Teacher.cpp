#include "iostream"
#include "string"
#include "Teacher.h"
using namespace std;  // do not forget it!!!!!
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

void Teacher::set_gender(string _gender)
{
	m_str_gender = _gender;
}
string Teacher::get_gender()
{
	return m_str_gender;
}

void Teacher::teach()
{
	cout << "class begins" <<endl; 
}

