#ifndef WORKER_H
#define WORKER_H
#include "Person.h"

class Worker : public Person 
{
	public:
		Worker();
		~Worker();
		void work();
		int m_int_salary;
};
#endif
