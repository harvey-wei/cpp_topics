#ifndef PERSON_H
#define PERSON_H
#include "string"
using namespace std;
class Person 
{
	public:
		Person();
		~Person();
		// normally constructor and destructor are declared as public!
		// otherwise the they will be automatically called when object is created and object go out of scope!!!
		void eat();	
		//all in the context public inheritance mode!!!
		string m_str_name;
	protected:    
		int m_int_age;   // it is inherited by subclass, nevertheless it is inaccessible !!!
		void rest();
	private:
		int m_int_height;
};

#endif
