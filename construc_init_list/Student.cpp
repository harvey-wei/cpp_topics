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

/* Q1: Why should a non-static const data member be initialized in a member initializer list or
 * a default initializer list.
 * https://stackoverflow.com/questions/63776841/memory-allocation-for-non-static-data-members-in-class
 * a const variable cannot be modified once the constructor definition, i.e. brace {} is being executed.
 * Constructor is called to allocate memory for non-static member.
 *
 * What kind of variables must be initialized using initializer list?
 * non-static data member, reference data member,
 *
 * Q2: Why should a reference data member should be initialized in the initializer list?
 * A: 1. As soon as an object is created compiler will allocate memory to reference member by
 *       running the constructor of class. Hence, before entering the brace part {} of constructor,
 *    2. Reference member should be initialized and declared at the same step. Inititialization of
 *       data member in the initializer list amounts to declaring and initializing at the same step.
 *     https://www.geeksforgeeks.org/can-c-reference-member-be-declared-without-being-initialized-with-declaration/
 * Q3: For initialization of member objects which do not have default constructor.
 * https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
 */
