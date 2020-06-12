#ifndef CLASS_H
#define CLASS_H
#include "iostream"
#include "string"
using namespace std;
/*
   Destructor do not take any argument and do not return anything!!!!
   Recall that constuctor can take some argument  and do not return anything neither!!!!
   Both of constuctor and Destructor are automatically invoked at proper time!
   Both of them will be created by compiler if no user-defined ones exist!
    By default, constructor and destructor are defined as public because they are invoked from outside the class !!!!!:
   */
class Teacher 
{
	public:
	Teacher(string _name = "Jim", int _age = 20);
	Teacher(const Teacher &tea);  // Note the prototype of copy constuctor
	~Teacher();    
	string get_name();
	int get_age();

	private:
	string m_str_name;
	int m_int_age;
	char *m_char_name;

};
#endif
