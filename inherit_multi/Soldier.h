#ifndef SOLDIER_H
#define SOLDIER_H
#include "Person.h"  // class Person will be inherited	
class Soldier : protected Person
{
	public:
		Soldier();
		~Soldier();
		void work();
	protected:
		int m_int_age;
};
#endif
