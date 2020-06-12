#include "Soldier.h"
#include <iostream>
using namespace std;
Soldier::Soldier()
{
	cout << "Soldier()" << endl;
} 
Soldier::~Soldier()
{
	cout << "~Solidier()" << endl;
}
void Soldier::work()
{
	cout << "Solier is fighting against enemy" <<endl;
}
		
