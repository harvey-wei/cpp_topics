#ifndef TANK_H
#define TANK_H

class Tank
{
	public:
		Tank(char code);
		~Tank();
		void fire();
		static int get_count();
		// In essence, const member function adds the const to the this pointer such that the const member functio can't modify the object!
		// static int get_count() const is illegal because static member function has no this pointer !!!!
	
	// As usual, static data member is also set to be private!!1
	private:
		static int s_int_count;  // Naming Convention: s for static. m for non-static member
		char m_char_code;
};

#endif
