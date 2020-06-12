#ifndef WORKER_H
#define WORKER_H
#include "Person.h"
// Worker inherits from Person on a public basis!

class Worker : public Person 
{
	public:
		Worker();
		~Worker();
		void work();
		int m_int_salary;
};
#endif
