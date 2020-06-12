#include "iostream"
#include "Coordinate.h"
using namespace std;

int main()
{
	Coordinate coor1(3,5);
	Coordinate coor2(1,2);
	Coordinate * const ptr_coor = &coor1; // & is to obtain the address!!!
	cout << ptr_coor->get_coor_y() <<endl;
	ptr_coor ->print_info();	

		
}
