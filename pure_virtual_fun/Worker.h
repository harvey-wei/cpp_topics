#ifndef WORKER_H
#define WORKER_H
#include "Person.h"
/* #include <string> */// Peron.h has included string!!
using namespace std;

class Worker : public Person
{
	protected:
		int m_int_age;

	public:
		// Constructor
		Worker(string _name, int _age); 

		// Destructor
		virtual ~Worker(){}
		// init list should be plcaced where the definition appears!!
		// No need to declare inherited pure virtual function!!
		// virtual work() =0 is inherited from the base class Person!!
		// Hence,Worker is also a abstract class which can not be instantiated!
};

#endif
