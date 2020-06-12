#include <iostream>
#include <string>
using namespace std;
/*
class: Person
data member: void
function member: void eat()
*/
class Person 
{
	public:
		Person()
		{
			cout << "Person()" << endl;
		}

		~Person()
		{
			cout << "~Person()" << endl;
		}

		void eat()
		{
			cout << "eat()" <<endl;
		}
};
/*
class: Worker
data member: m_str_name;
member function: work()
*/
class Worker : virtual public Person
{
	public:
		Worker(string _name = "John")
		{
			m_str_name = _name;
			cout << "Worker()" <<endl;
		}
		
		virtual	~Worker()
		{
			cout << "~Worker()" <<endl;
		}
		
		void work()
		{
			cout << m_str_name << endl;
			cout << "working" <<endl;
		}
	protected:  // protected can be inherited!!!
		string m_str_name;
};

/*
class: Children
data member: m_int_age
member function: play()
*/
class Children : virtual public Person
{
	public:
		Children(int _age = 10)
		{
			cout << "Children()" <<endl;
			m_int_age = _age;
		}

		virtual ~Children()
		{
			cout << "~Children()" <<endl;
		}

		void play()
		{
			cout << m_int_age << endl;
			cout << "playing" << endl;
		}
	protected:
		int m_int_age;
};

class Child_Labor: public Worker, public Children   // Worker is created before Children
{
	public:
		// Derived object can not initialize the base-class part directly
		// However, a derived class must use a base-class constructor to initialize its base-class part
		// as follows, initializer list
		Child_Labor(string _name, int _age): Worker(_name), Children(_age)
		{
			cout << "Child_Labor()" <<endl;
		}

		~Child_Labor()
		{
			cout << "~Child_Labor()" << endl;
		}
};
int main()
{
	Child_Labor *p = new Child_Labor("Bob", 13);
	if(!p)
	{
		cout << "Allocation fails" << endl;
	}
	p->eat();
	p->work();
	p->play();

	delete p;
	p = NULL;
	return 0;
}
