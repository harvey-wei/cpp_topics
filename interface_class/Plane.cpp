#include "Plane.h"
#include <iostream>
using namespace std;

Plane::Plane(string _num)
{
	m_str_num = _num;	
}
/* void Plane::takeoff() */
/* { */
/* 	cout << "Plane is taking off " << endl; */
/* } */
/* void Plane::land() */
/* { */
/* 	cout << "Plane is landing " << endl; */
/* } */
void Plane::print_num()
{
	cout << "Plane_Num is " << m_str_num << endl;
}
