#include "Person.h"
#include "iostream"
using namespace std;
Person::Person()
{
	cout << "Person()" <<endl;
}

Person::~Person()
{
	cout << "~Person()" <<endl; 
}

void Person::eat()
{
	m_str_name = "Jim";  
	m_int_age = 20;
	cout << "eat()" <<endl;
}
// protected and private member can be accessed by member fucntion !!!!kkk 

void Person::rest()
{
	cout << "age is " << m_int_age <<endl;
}
