#include "iostream"
#include "string"
using namespace std;

class Student
{
	public:
		string name;
		int age;

		void print_name()
		{
			cout << "Name is " << name <<endl;
		}

		void print_age()
		{
			cout << "Age is " << age << endl;
		}
};
int main_as()
{
	Student student_1;
	Student student_2; 
	student_1.age = 25;
	student_1.name = "Harvey Wei";

	student_1.print_name();
	student_1.print_age();
	
	Student stuent_3;

	return 0;
}
