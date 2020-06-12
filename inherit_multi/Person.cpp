#include "Person.h"
#include "iostream"
using namespace std;
Person::Person(string _gender, string _name)
{
	m_str_name = _name;
	m_str_gender = _gender;
	cout << "Person()" <<endl;
}
Person::~Person()
{
	cout << "~Person()" <<endl; 
}
void Person::play()
{
	cout << "Gender is " << m_str_gender;
	cout << "Name is " << m_str_name;
}
void Person::work()
{
	cout << "Person::work()" <<endl;
}
