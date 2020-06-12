#include "Fighter.h"
#include <iostream>
using namespace std;

Fighter::Fighter(string _num): Plane(_num)
{
	cout << "Fighter() "<< endl;
}

void Fighter::takeoff()
{
	cout << "Fighter is taking off " << endl;
}

void Fighter::land()
{
	cout << "Fighter is landing " << endl;
}

