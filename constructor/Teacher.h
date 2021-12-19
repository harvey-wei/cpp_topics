#ifndef TEACHER_H
#define TEACHER_H

#include "iostream"
#include "string"
using namespace std;
//split the definition and declaration into different files
// such that sharing is reduced to adding the header file!!!
// Note that .h file can include variable definition and function definition
// Inline function definition must placed in the header files for the compiler to insert it to he call-points!
class Teacher 
{
	public:
	//Overloaded Constructors
	Teacher();  // default constructor
	Teacher(string name, int age = 20); // collide with Teacher()
	// It is good practice to put default value only in the declaration!!!!

	// The following is a series of function declarations.
	void set_name(string _name);
	string get_name();
	void set_age(int _age);
	int get_age();
    
	private:
	string m_str_name;
	int m_int_age;

};

#endif
