#include "Tank.h"
#include <iostream>
using namespace std;

// Initialize the staic varible of class(Class varible)
int Tank::s_int_count = 0;  // static varible must be Initialized from outside class

//Constuctor, increment s_int_count

Tank::Tank(char _code)
{
	m_char_code = _code;
	s_int_count ++; // non-static function can access staic object(staic lives longer than non-staic in the memory)
	cout << "Tank" << endl;
}

Tank::~Tank()
{
	s_int_count --;
	cout << "~Tank" << endl;
}

// non-static member function can access the static function / staic data
// static functon lives longer than non-staic member functon in the memory!!
void Tank::fire()
{
	cout << "Tank -- Fire" << endl;
	get_count(); // 
}

// static member function can not access the non-staic function / non-static variables
int Tank::get_count()  // no static longer!!!
{
	return s_int_count;
}
