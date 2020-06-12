#include "iostream"
#include "string"
using namespace std;

class Student
{
	public:
		void set_name(string _name)
		{
			m_str_name = _name;
		}

		string get_name()
		{
			return m_str_name;
		}

		void set_gender(string _gender)
		{
			m_str_gender = _gender;
		}

		string get_gender()
		{
			return m_str_gender;	
		}
		
		int get_score()
		{
			return m_int_score;
		}

		void init_score()
		{
			m_int_score = 0;   // private member can be accessed indirectly via public function
		}
		
		void study(int _score)
		{
			m_int_score += _score; // private member can be modified indirectly by public function
		}
	private:
		string m_str_name;
		string m_str_gender;
		int m_int_score;
};
// By convention, the modifier public comes before private!!!!
// Naming convention:
// data member is preceded by m, short for member.
// and followed by type such str(for string),int and so on
// the temporary variable(formal parameter) used to assignment is prefixed with underscore _
int main()
{
	Student stu;
	stu.init_score(); // It is a better practice to initialize to avoid undefined value!!!
	// different compilers have different interpretation!!!
	stu.set_name("Harvey Mao");
	stu.set_gender("male");
	stu.study(4);
	stu.study(6);

	cout << stu.get_name() << "  " << stu.get_gender() << " " << stu.get_score() <<endl;


	return 0;
}
