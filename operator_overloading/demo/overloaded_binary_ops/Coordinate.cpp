#include "Coordinate.h"
#include <iostream>
#include <string>
using namespace std;  // ostream !!

Coordinate::Coordinate(int _x, int _y)
{
	m_int_x = _x;
	m_int_y = _y;
}

int Coordinate::get_x()
{
	return m_int_x;
}

int Coordinate::get_y()
{
	return m_int_y;
}
// Operator Function as a member function!!
// Returning an reference allows you chain this fucntion calls!!!
// -coor return an Coordinate
// -(-coor) is legal!!!!
/* Coordinate & Coordinate::operator-() */
/* { */
/* 	// reverse the sign of x and y */
/* 	// utilize the implicit this pointer to the current object */
/* 	m_int_x = - m_int_x;  // because this operator functio is member function.hence no need to use this pointer! */
/* 	this->m_int_y = - this->m_int_y; */

/* 	return *this;   // return the current object which is assigned to a reference! */
/* } */

// prefix increment(expression valus equals the incremented operand)
Coordinate & Coordinate::operator++()   
{
	m_int_x ++;
	m_int_y ++;  // equivalently, ++m_int_y

	return *this;  // value of expression
}

Coordinate Coordinate::operator++(int)
{
	Coordinate old(*this); // call default copy Constructor
	m_int_x ++;
	m_int_y ++;

	return old;
}

Coordinate & operator-(Coordinate & coor)
{
	coor.m_int_x = -coor.m_int_x;
	coor.m_int_y = -coor.m_int_y;

	return coor;
}


/* Coordinate Coordinate::operator+(const Coordinate & coor) */
/* { */
/* 	return Coordinate(this->m_int_x + coor.m_int_x, */ 
/* 			this->m_int_y + coor.m_int_y); */

/* 	// using temporay variable is also possible */
/* } */

// Friend Function of Coordinate hence it can access the private and protected part
 //such as m_int_x and m_int_y
Coordinate operator+(const Coordinate &c1, const Coordinate &c2)
{
	return Coordinate(c1.m_int_x + c2.m_int_x,
			c1.m_int_y + c2.m_int_y);
}

// The first parameter is not the this pointer hence, binary ops << can not be member function only be a friend function
// cout << output!!!
ostream & operator<<(ostream &output, Coordinate &coor)
{
	// output is similar to cout!!!!
	// cout can be assigned to output!!!
	// ouput is ouput stream object receiving the value needed to be displayed on the screen
	output << coor.m_int_x << "," << coor.m_int_y;
	return output; 
}

//

int Coordinate::operator[](int ind)
{
	try
	{
		if(ind == 0)
		{
			return m_int_x;	
		}
		else
			if(ind == 1)
			{
				return m_int_y;
			}
			else
			{
				throw string("index must be either 0 or 1!");
			}
	
				
	}
	catch(string & e)   // catch what is thrown and assign it to e
	{
		cout << e << endl;	
		exit(1);   // 1 means that the program fails!
		//exit() terminates the calling process without executing the rest code which is after the exit() function.
	}
}

int Coordinate::operator()(int factor)
{
    return factor * 10;
}

int Coordinate::call_parentheses(int factor)
{
    return operator()(factor);
}
