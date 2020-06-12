#include <iostream>
#include <string>
using namespace std;
// It is a good habit to write explanatory// illustrative notes before class declaration!!
/**
* Class: Person
* Data Member: m_str_name
* Member function: eat();
**/
class Person
{
	public:
		string m_str_name;
		void eat()
		{
			cout << "The person is  eating" <<endl;
		}
};

/**
* Class: Soldier
* Public derivation from Person
* Data Member: m_str_code;
* Member function: attack()
*/

class Soldier : public Person
{
	public:
		string m_str_code;
		void attack()
		{
			cout << "Fire!!!" <<endl; // shoot bullets from the gun!!!
		}
};
int main()
{
	Soldier * ptr_soldier = new Soldier;  // instantiate from the heap!!!
	if(!ptr_soldier)
	{
		cout << "Allocation fails!" << endl;
		exit(0);
	}

	ptr_soldier->m_str_name = "Jim";
	ptr_soldier->m_str_code = "592";

	cout << ptr_soldier->m_str_name <<endl;
	cout << ptr_soldier->m_str_code <<endl;

	ptr_soldier->attack();  // () is a must to invoke a functiono
	ptr_soldier->eat();
	return 0;
}
