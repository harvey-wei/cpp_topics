#ifndef COORDINATE_h
#define COORDINATE_h
class Coordinate 
{
	public:
		/* Coordinate(int _coor_x = 11, int _coor_y = 0); */	
		Coordinate(int _x, int _y);
		~Coordinate();
		void set_coor_x(int _x);
		void set_coor_y(int _y);
	private:
		int get_coor_x();
	protected:
		int get_coor_y();
	private:
		int m_int_coor_x;
		int m_int_coor_y;
};
#endif
