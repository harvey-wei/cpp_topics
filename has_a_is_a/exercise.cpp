#include <iostream>
#include <string>
using namespace std; //  all names in C++ Standard Library is in std!!!

/**
*Class: Person
*Data Member: m_str_name
*Member Function: attack()
*/

class Person 
{
	public:
		string m_str_name;
		void attack()
		{
			cout << "attack" <<endl;
		}
};

/*
*class:Soldier
* derived by public Person
* data member: m_str_name;
* member function: attack()
*/

class Soldier : public Person
{
	public:
	string m_str_name;
	void attack()
	{
		cout << "Fire!!!" << "Shoot bullet from a gun" << endl;
	}
};

int main()
{
	Soldier soldier;
	soldier.m_str_name = "Tomato";
	soldier.Person::m_str_name = "Jim";

	cout <<soldier.m_str_name << endl;
	cout << soldier.Person::m_str_name <<endl;

	soldier.attack();
	soldier.Person::attack();

}
