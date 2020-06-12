#ifndef PERSON_H
#define PERSON_H
#include "string"
using namespace std;
class Person 
{
	public:
		string m_str_name;
		int m_int_age;
		Person();
		~Person();
		// normally constructor and destructor are declared as public!
		// otherwise the they will be automatically called when object is created and object go out of scope!!!
		void eat();	
};

#endif
