#include <iostream>
#include "Infantry.h"
// Infantry.h also include Soldier.h
using namespace std;

int main()
{
	Soldier soldier;
	soldier.work();  // here work() is member defined in Soldier not inherited from Person
	// because the work() ofjj
	/* soldier.play(); */ 
	// Soldier is derived from Person with protected mode!!!
	// so public play() of Person becomes protected member of Soldier!!!
	return 0;
	// kljlkjlkjlj wew 
}
