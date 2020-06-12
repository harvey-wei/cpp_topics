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
	protected:   // By/In comparison with private, protected member is accessible to subclass
		string m_str_name;
	protected:    
		int m_int_age;   // it is inherited by subclass, nevertheless it is inaccessible !!!
		void rest();
		// private members(data and function) are inherited by the subclass but are invisible to subclass.
	private:
		int m_int_height;
};

#endif
