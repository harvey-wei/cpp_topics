#include <iostream>
#include <string>
using namespace std;
// It is better to provide a virutal destructor in base class!!!

class Farmer
{
public:
Farmer(string _str_name = "Jack")
{
	cout << "Farmer()" << endl;
}

virtual ~Farmer()                  //declare destructor of base class as virtual in order to help release the heap space of subclass!
{
	cout << "Farmer" << endl;
}

void sow()
{
	cout << "Farmer is sowing!" <<endl;
}
protected:
string m_str_name;
};

class Worker
{
public:
Worker(string _str_ID = "001")
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
protected:          // protected member will be inherited!!
string m_str_ID;
};
// public mode of inheritance guarantees IS A relation
class Migrant_worker : public Worker, public Farmer
{
public:
/* Migrant_worker(string _name, string _ID):Farmer(_name), Worker(_ID)  // Init List */
Migrant_worker(string _name, string _ID)
{
	m_str_ID = _ID;          // inherit from Worker
	m_str_name = _name;         // inherit from Farmer
	cout << "Migrant_worker()" <<endl;
}

~Migrant_worker()
{
	cout << "~Migrant_worker()" << endl;
}
};


int main()
{
	Migrant_worker *p = new Migrant_worker("Merry","100");
	p->carry();
	p->sow();
	delete p;
	p = NULL;

}
