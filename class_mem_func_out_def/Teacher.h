#include "string"
using namespace std;
class Teacher
{
	public:
		// only declare member function
		// function definitions are placed outside 
		// in the same file or in the other file
		void set_name(string _name);
		string get_name();
		void set_gender(string _gender);
		string get_gender();
		void set_age(int _age);
		int get_age();
		void teach();
	private:   // also can contain function!!
		string m_str_name;
		string m_str_gender;
		int m_int_age;
}; // class declaration must end with semicolon!!!
