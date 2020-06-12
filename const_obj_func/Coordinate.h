#ifndef COORDINATE_h
#define COORDINATE_h
class Coordinate 
{
	public:
		/* Coordinate(int _coor_x = 11, int _coor_y = 0); */	
		Coordinate(int _x, int _y);
		~Coordinate();
		void set_coor_x(int _x);  // indeed void set_coor_x(Coordinate *this, int _x)
		void set_coor_x(int _x) const;  // amonts to void set_coor_x(const Coordinate *this)!!!which implies that you can make changes to the object to which the this point
		// That means that it need a object which can be read and written!!
		// const Coordinate coor: const will be act Coordinate *this,i.e. coor become read-only. Correpondingly, the data member of coor is also read-only!!!!
		// Do not forget the explicit parameter "this" in member function !!!!!!
		// set_coor_x and set_coor_y which will change the data member can not be defined as const member function !!
		void set_coor_y(int _y);
		int get_coor_x();
		int get_coor_y();
	private:
		int m_int_coor_x;
		int m_int_coor_y;
};
#endif
