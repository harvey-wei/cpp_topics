/*

*/	


#include <iostream>
#include <string>
#include "Tank.h"

using namespace std;

int main()
{
	/* Tank t1('A');  // single quote for char type */
	Tank * p = new Tank('A');
	if(!p) {cout << "Fail to allocate heap space" << endl;}
	/* cout <<	Tank::get_count() << endl; */
	cout << p->get_count() << endl;

	Tank * q = new Tank('B');
	if(!q) {cout << "Fail to allocate heap space" << endl;}
	cout << Tank::get_count() << endl;
	cout << 

	delete p;
	p = nullptr;
	delete q;
	q = nullptr;
	
	cout << Tank::get_count() << endl;// You can access the get_count() only by class name followed by scope resolution operator!


	return 0;
}
