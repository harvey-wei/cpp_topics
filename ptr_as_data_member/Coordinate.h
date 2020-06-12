#ifndef COORDINATE_H
#define COORDINATE_H
class Coordinate 
{
	public:
		Coordinate(int _x = 0, int _y = 0);
		~Coordinate();
		void set_x(int _x);
		void set_y(int _y);
		int get_x();
		int get_y();
	private:
		int m_i_x;
		int m_i_y;
};
#endif
