#ifndef PERSON_H
#define PERSON_H
#include "string"
using namespace std;
class Person 
{
	public:
		Person(string _gender = "male", string _name = "Jim" );
		~Person();
		void play();
		void work();
	private:
		string m_str_gender;
	protected:
		string m_str_name;

};
#endif
