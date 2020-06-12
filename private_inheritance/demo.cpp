#include <iostream>
#include <string>
using namespace std;
// It is better to provide a virtual destructor in base class!!!
class Person 
{
	public:
		Person(string _color = "blue")
		{
			m_str_color = _color;
			cout << "Person()" << endl;
		}
		virtual ~Person()  
		{
			cout << "~Person"<<endl;
		}// in order the subclass in the heap is also disposed of!!!
		// Even if ~Person() does nothing, it is also needed to achieve the automatic release of memory heap!!
		void print_color()
		{
			cout << m_str_color <<endl;
			cout << "Person--print_color" << endl;
		}

	protected: // such that protected member can be inherited
		string m_str_color;
};
class Farmer:virtual public Person
{
	public:
		Farmer(string _str_name = "Jack", string _color = "blue"):Person("Farmer"+_color) // here init list Person() is constuctorj
		{
			cout << "Farmer()" << endl;
		}

		virtual ~Farmer()  //declare destructor of base class as virtual in order to help release the heap space of subclass!
		{
			cout << "Farmer" << endl;
		}

		void sow()
		{
			cout << "Farmer is sowing!" <<endl;
		}
	protected:
		string  m_str_name;
};

class Worker :virtual public Person
{
	public:
		Worker(string _str_ID = "001", string _color = "blue"): Person("Worker"+_color) // avoid modifying the Woker constuctor
		{
			m_str_ID = _str_ID;
			cout << "Worker()" <<endl;
		}
		
		virtual ~Worker()
		{
			cout << "~Worker()" <<endl;
		}
		
		void carry()
		{
			cout << m_str_ID <<endl;
			cout << "Worker is carrying !" <<endl;
		}
	protected:  // protected member will be inherited!!
		string m_str_ID;
};
// public mode of inheritance guarantees IS A relation
class Migrant_worker: public Worker, public Farmer
{
	public:
	/* Migrant_worker(string _name, string _ID):Farmer(_name), Worker(_ID)  // Init List */
		// The initializer here is vastly distinct from that in const variable!!!
		// Here the init list  is constuctor of superclass. Hence you should pass matching argument!!!!
		// Pros: If superclass's data member name is changed!! No need make changing in the sublcass!!
		// Constructor and destructor are not inherited but they can be called!!!
	Migrant_worker(string _name, string _ID,string _color):Farmer(_name,_color), Worker(_ID,_color) 
	{
		/* m_str_ID = _ID;  // inherit from Worker */
		/* m_str_name = _name; // inherit from Farmer */
		cout << "Migrant_worker()" <<endl;
		
	}

	~Migrant_worker()
	{
		cout << "~Migrant_worker()" << endl;
	}
};


int main()
{
	Migrant_worker *p = new Migrant_worker("Merry","100","Yellow");
	p->Farmer::print_color(); // two print_color so you should use scope operator!!
	p->Worker::print_color();  // Similarly, two m_str_color !!!kkkkkkkkkkkkkkkkkkkkkkkkkkk
	delete p;
	p = NULL;

}
