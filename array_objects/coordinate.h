class Coordinate 
{
	public:
		Coordinate(int _x = 0, int _y = 0);	
		~Coordinate();
		void set_coor_x(int _x);
		void set_coor_y(int _y);
		int get_coor_x();
		int get_coor_y();
	private:
		int m_int_x;
		int m_int_y;
};
