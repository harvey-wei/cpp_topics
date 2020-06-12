#ifndef INFANTRY_H
#define INFANTRY_H
#include "Soldier.h"
// Soldier is derive from Person with protected mode!!!
// Consequently, you can not access public member of Person from outside the Soldier class!!
class Infantry : public Soldier
{
	public:
		void attack();
};
#endif 
