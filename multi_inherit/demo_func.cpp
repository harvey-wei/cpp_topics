#include <iostream>
#include <string>
using namespace std;

/*
			Person 
			   |
			  \|/
			Solider 
			   |
			  \|/
			Infantry
Person is the base class of Solider
Soldier is the base class of Infantry
=> Infantry is the indirect subclass of Person  
=> All Mode of Inheritance is public
=> Infantry IS A Person!!!!!!
=> Infantry and Solider can act as  Person Instance!!!
=> Infantry and Soldier can be used to initialize Person object
=> or Under IS A relation, subclass or indirect subclass can also be assigment to supercalss or indirect superclass
=> can also be the object to which the superclass points 
=> can also be passed to the function whose parameter type is of the superclass type!!
=> Nevertheless, the reverse is illegal!!
*/

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
			cout << "Soldier also likes playing!i  "<<x<<endl;
		}
		void work()
		{
			m_int_age = 40;
			/* Person::m_int_age = "Age of person!!!";  // the access method is analogous to that in scope!!!! */
			cout << "Soldier is working!" <<endl;
		}
		
	protected:
		int m_int_age;
		/* string m_str_name; */
		int m_int_number;
};

class Infantry :public Soldier 
{
	public:
		Infantry(string _name = "Jack", int age = 30)
		{
			m_str_name = _name;
			/* m_int_age = age; */
			cout << "Infantry()" <<endl;
		}

		~Infantry()
		{
			cout << "~Infantry()" <<endl;	
		}

		void attack()
		{
			// print out the inherited data member
			cout << m_str_name <<endl;
			cout << m_int_age <<endl;
			cout << "Infantry is attack enenmy!!";
		}
		
};
// put the definition of function before the main to avoid the declaration
void test1(Person p) // call copy constructor!!!
{
	p.play();   // call the Person::play()
}
void test2(Person *p)
{
	p->play(); // also call the Person::play

}
void test3(Person &p)
{
	p.play(); // also call the Person::play()
}

int main()
{
	// Soldier is derive from Person
	// Soldier is a Person
	// Soldier act as a person to some extent!!!
	/* Person p; */
	/* Soldier s; */ 
	/* test3(p); // remember how to pass value to reference parameter!!!no prefix!!!!! */
	/* test3(s); // note that reference is merely a alias. Unlike pass to regular variable, */
	// no such reference variable is  created, reference is just a alias of referenced variable(share address and value)
	/* test2(&p); // pass address!!! no new object is  created!!!!! */
	/* test2(&s); */
	Infantry infantry;
	// Intuitively, the superclass is created before the subclass
	// the subclass is disposed of before superclass	
	// Inheritance chain!!!!
	test1(infantry);
	test2(&infantry);
	test3(infantry);
	infantry.play(7);  
	infantry.Person::play();
	// Person::play() is hidden in Soldier. Infantry inherit from Solider. Hence Person::play() is also hidden in Infantry;
	
	return 0;
}
