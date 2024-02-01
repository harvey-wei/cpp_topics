#ifndef STUDENT_H
#define STUDENT_H
#include "string"
using namespace std;
class Student 
{
	public:
		Student(){}
		Student(string & _name);
	private:
		string m_str_name;
};

class Teacher 
{
	public:
		Teacher(int _num_stu, string _name = "Kevin", int _age = 25); 
		// Note that it is better put default value in declaration not in definition.
		// Note that initializer list should be placed where the definition occurs! 
		string get_name();
		int get_age();
		int get_num_stu();
	private:
		string m_str_name;
		int m_int_age;
		const int m_num_of_stu;
};
// For more details on initializer list, you can refer to the post at https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
// Const object must be initialized either when created or via initializer list along with constructor.
class Circle
{
	public:
		// constructor with initializer list
        // also use default value
		Circle(double _radius, double _center):m_db_Pi(3.14), m_db_radius(_radius), m_db_center(_center)
		{
			/* m_db_Pi = 3.14;	// const object can not be assigned! */
		}
		double get_area();
	private:
		const double m_db_Pi;
		const double m_db_radius;
		const double m_db_center;
};
#endif // STUDENT_H
