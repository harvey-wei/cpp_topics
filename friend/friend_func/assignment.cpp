#include <iostream>
using namespace std;

/**
Class Name: Coordinate
friend function: display()
data members: m_int_x, m_int_y
**/
class Coordinate 
{

    friend void display(Coordinate & c);

	public:
		//constructor
		Coordinate(int _x, int _y)
		{
			m_int_x = _x;
			m_int_y = _y;
		}
	
	private:
		int m_int_x;
		int m_int_y;
};

/**
Purpose: display the m_int_x and m_int_y on the screen 
input: Coordinate &
output: void
**/
void display(Coordinate & c)
{
	cout << "(" << c.m_int_x << "," << c.m_int_y  << ")" << endl;
}


int main()
{
	Coordinate c(10, 23);
	display(c);

	return 0;
}
