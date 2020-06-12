#include "Dustman.h"
#include <iostream>
#include <string>
using namespace std;
// Init list contaion the base-class constructor!!!!!
// Init list should be placed on the defi unlike the default!!!!
Dustman::Dustman(string _name, int _age) : Worker(_name, _age)
{
	cout << "Dustman()" << endl;
}

// So Dustman is regular class which can be instantiated!
void Dustman::work()
{
	cout << m_str_name << "at the age of " << m_int_age << "is working " << endl;
}
