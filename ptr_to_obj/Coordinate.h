#ifndef COORDINATE_H
#define COORDINATE_H
class Coordinate 
{
	public:
		Coordinate(int _x = 0,int _y = 0); // default value occurs only in declaration if dec and def are separated!!
		~Coordinate();
		void set_x(int _x);
		void set_y(int _y);
		int get_x();
		int get_y();
		int add_x(Coordinate coor);
		int add_y(Coordinate coor);
	private:
		int m_int_x;
		int m_int_y;
};
#endif
