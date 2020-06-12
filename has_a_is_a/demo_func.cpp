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
		Person(string _name = "Jim")
		{
			cout << "Person()" <<endl;
			m_str_name = _name;
		}
		// virtual keyword is implicted inherited by subclass
		virtual ~Person()  // virtual help the subclass object to release the heap memory!!!
		{
			cout << "~Person" <<endl;
		}
		Person(const Person & _person)
		{
			cout << "Person(const Person & _person)" << endl;	
		}
	protected:  // can be inherited by subclass
	string m_str_name;
};

class Soldier: public Person
{
	public:
		Soldier(string _name = "Kevin", int _age = 20)
		{
			m_int_age = _age;
			m_str_name = _name;  // derived from Person!!!!
			cout << "Soldier()" <<endl;
		}
		virtual ~Soldier()  // It is better to write out the virtual explicitly !!k
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
		
	private:
		int m_int_age;
		/* string m_str_name; */
		int m_int_number;
};
// put the definition of function before the main to avoid the declaration
void test1(Person p)
{
	p.play();
}
void test2(Person *p)
{
	p->play();

}
void test3(Person &p)
{
	p.play();
}
int main()
{
	// Soldier is derive from Person
	// Soldier is a Person
	// Soldier act as a person to some extent!!!
	Person p;
	Soldier s; 
	/* test3(p); // remember how to pass value to reference parameter!!!no prefix!!!!! */
	/* test3(s); // note that reference is merely a alias. Unlike pass to regular variable, */
	// no such reference variable is  created, reference is just a alias of referenced variable(share address and value)
	test2(&p); // pass address!!! no new object is  created!!!!!
	test2(&s);
	
	
	return 0;
}
