#include <iostream>
#include <string>
using namespace std;

/*
   Class Name: Coordinate
   Data Members: m_i_x, m_i_y
   Member Function: Constructor, overloaded --(both prefix and suffix versions)
*/
// By default, operator--() is prefix,  operator --(int) is suffix version!(as member function)
// decrement is unary ops while + is binary ops!

class Coordinate
{
	friend ostream & operator<<(ostream & output, Coordinate coor);
	public:
		// Constuctor
		Coordinate(int _x, int _y)
		{
			m_i_x = _x;
			m_i_y = _y;
		}

		// pre-decrement overloading  value of expr is the updated one!
		Coordinate & operator--()
		{
			this->m_i_x --;
			this->m_i_y --;

			return *this;
		}

		//post-decrement overloading value of expr is the old one

		Coordinate operator--(int)
		{
			Coordinate old(*this);
			this->m_i_x --;
			this->m_i_y --;

			return old;
		}

		// plus ops overloading
		Coordinate operator+(const Coordinate & coor)
		{
			return Coordinate(this->m_i_x + coor.m_i_x, this->m_i_y + coor.m_i_y);
		}

		// overloading output ops <<

	private:
		int m_i_x;
		int m_i_y;
};

//cout << coor is interpreted as  cout << output!!!
ostream & operator<<(ostream & output, Coordinate coor)
{
	// Upside of overloaded << is that you can put the compliated struncture into ostream !!!
	output << "("<<coor.m_i_x << ", " << coor.m_i_y << ")";

	return output;
}

int main()
{
	Coordinate coor1(1, 3);
	Coordinate coor2(2, 4);
	Coordinate coor3(0, 0);

	coor1--;
	cout << "coor1" << coor1 << endl;
	--coor2;
	cout << "coor2" << coor2 << endl;
	coor3 = coor1 + coor2;

	cout << "coor3" << coor3 << endl;

	return 0;
}


/** Q: Is space allowed between operator keyword and operator sign?
  * A: Yes.
  * ref: https://www.geeksforgeeks.org/operator-overloading-c/
  *
  * Q: Is operator followed by operator sign acting as function name?
  * A: Yes.
  *
  * Q: What operators can we not overload?
  * A: sizeof, typeid, scope resolution(::), Class member access operators (.(dot), .* (pointer to member operator))
  * ref: https://www.geeksforgeeks.org/operator-overloading-c/
  */
