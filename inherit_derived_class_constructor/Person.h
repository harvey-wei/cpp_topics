#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;

class Person 
{
	private:
		string m_str_name;
		int m_int_age;

	public:
		// constructor with initalizer list!
		// initalizer list is defined in the function define .cpp!!!!
		Person(const string & _name = "", int _age = 0);

		// retrieve the name
		const string & get_name() const;

		
};



#endif

