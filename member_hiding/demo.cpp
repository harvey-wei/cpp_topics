#include <iostream>
#include <string>
using namespace std;

class Person 
{
	public:
		void play()
		{
			cout << "Person--play()" <<endl;
			cout << m_str_name <<"Human likes playing!" << endl;
		}
		Person()
		{
			cout << "Person()" <<endl;
			m_str_name = "Merry";
		}
		~Person()
		{
			cout << "~Person" <<endl;
		}
	protected:  // can be inherited by subclass
	string m_str_name;
};

class Soldier: public Person
{
	public:
		Soldier()
		{
			cout << "Soldier()" <<endl;
		}
		~Soldier()
		{
			cout <<"~Solider()" << endl;
		}
		
		void play(int x)
		{
			cout << "Soldier also likes playing!"<<endl;
		}
		void work()
		{
			m_int_age = 40;
			/* Person::m_int_age = "Age of person!!!";  // the access method is analogous to that in scope!!!! */
			cout << "Soldier is working!" <<endl;
		}
		
	int m_int_age;
	private:
		string m_str_name;
		int m_int_number;
		
};

int main()
{
	// The functions with the same name in sublcass and superclass respectively are impossible to overloading!!!
	Soldier soldier;
	soldier.play(7);         // by default, play() is resolved as the play belonging to Solider class!;sspl:s
	soldier.work();
	soldier.Person::play();  // prefix play() with Person:: Person is class Name!!!!
	soldier.m_int_age = 23;
	/* soldier.Person::m_int_age = "Jim Sun Play with person"; */
	cout << sizeof(soldier.m_int_age) <<endl;
	cout<< soldier.m_int_age << endl;
	/* cout << sizeof(soldier.Person::m_int_age) <<endl; */

	/* cout << soldier.Person::m_int_age << endl; */
	return 0;
}
