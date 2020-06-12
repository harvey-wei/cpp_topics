#ifndef PLANE_H
#define PLANE_H
#include "Flying.h"
#include <string>
using namespace std;
/*
class: Plane derived from Flying class type
member function: Constructor, void takeoff(), void land(), print_code()
data member: m_str_num
*/
class Plane
{
	public:
		Plane(string _num = "001");
		/* virtual void takeoff(); */
		/* virtual void land(); */
		void print_num();
	protected:
		string m_str_num;
};
#endif

