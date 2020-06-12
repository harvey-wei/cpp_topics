#include <iostream>
#include <string>
#include "Person.h"
using namespace std;



Person::Person(string _name)
{
	m_str_name = _name;
	cout << "Person()" << endl;
}

Person::~Person()
{
	cout <<"~Peron()" << endl;
}
// No implementation of work (pure virtual function) such that Person is a Abstract Class which can not be instantiated whether from stack or from heap
