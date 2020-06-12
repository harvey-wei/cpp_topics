#ifndef CLASS_H
#define CLASS_H
#include "iostream"
#include "string"
using namespace std;
class Teacher 
{
	public:
	Teacher(string _name = "Jim", int _age = 20);
	Teacher(const Teacher &tea);  // Note the prototype of copy constuctor
	string get_name();
	int get_age();

	private:
	string m_str_name;
	int m_int_age;

};
#endif
