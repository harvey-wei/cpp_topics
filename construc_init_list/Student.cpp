#include "string"
#include "Student.h"
#include "iostream"
using namespace std;
Student::Student(string & _name)
{
	m_str_name = _name;
}

/* https://stackoverflow.com/questions/72885601/how-are-member-variables-initialized-and-constructed */
Teacher::Teacher(int _num_stu,string _name,int _age)
    :m_str_name(_name),m_int_age(_age),m_num_of_stu(_num_stu)
     // call the constructor of the corresponding type and these three variables start their lifetime.
{
	cout <<" Teacher::Teacher(string _name,int _age):m_str_name(_name),m_int_age(_age)" <<endl;

}

int
Teacher::get_age()
{
	return m_int_age;
}

string
Teacher::get_name()
{
	return m_str_name;
}

int
Teacher::get_num_stu()
{
	return m_num_of_stu;
}

double
Circle::get_area()
{
	return m_db_Pi * m_db_radius * m_db_radius;
}
