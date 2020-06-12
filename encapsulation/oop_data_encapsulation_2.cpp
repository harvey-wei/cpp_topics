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
	private:
		string m_str_name;

};

int main()
{
	Student * ptr_stu = new Student;
	ptr_stu -> set_name("harvey mao");
	cout << "name is " << ptr_stu -> get_name() << endl;
	return 0;
}
