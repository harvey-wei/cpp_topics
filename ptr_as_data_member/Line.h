#ifndef LINE_H
#define LINE_H
#include "Coordinate.h"
class Line 
{
public:
	Line(int x1, int y1, int x2, int y2);
	~Line();
	void print_info();
private:
	Coordinate *m_ptr_coor_A;  // pointer for simple initializing !!!
	Coordinate *m_ptr_coor_B;

	// you should make pointer point to some location in the memory first!!!
};
#endif
