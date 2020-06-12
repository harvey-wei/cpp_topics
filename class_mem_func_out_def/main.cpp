#include "iostream"
#include "string"
#include "Teacher.h"
using namespace std;
/* class Teacher */
/* { */
/* 	public: */
/* 		// only declare member function */
/* 		// function definitions are placed outside */ 
/* 		// in the same file or in the other file */
/* 		void set_name(string _name); */
/* 		string get_name(); */
/* 		void set_gender(string _gender); */
/* 		string get_gender(); */
/* 		void set_age(int _age); */
/* 		int get_age(); */
/* 		void teach(); */
/* 	private:   // also can contain function!! */
/* 		string m_str_name; */
/* 		string m_str_gender; */
/* 		int m_int_age; */
/* }; // class declaration must end with semicolon!!! */
/* // Encapsulation: data member should be private; */
/* // All operations on data member only can be performed via public function */
/* // class only provide interface to user but hide date and concrete implementation */

/* // stick to the above rules!!! */
/* // Hence, set and get are standard public function */

/* void Teacher::set_name(string _name) */
/* { */
/* 	m_str_name = _name; */
/* } */
/* string Teacher::get_name() */
/* { */
/* 	return m_str_name; */
/* } */

/* void Teacher::set_age(int _age) */
/* { */
/* 	m_int_age = _age; */
/* } */

/* int Teacher::get_age() */
/* { */
/* 	return m_int_age; */
/* } */

/* void Teacher::set_gender(string _gender) */
/* { */
/* 	m_str_gender = _gender; */
/* } */
/* string Teacher::get_gender() */
/* { */
/* 	return m_str_gender; */
/* } */

/* void Teacher::teach() */
/* { */
/* 	cout << "class begins" <<endl; */ 
/* } */
int main()
{
	// Instantiate a class from the stack where memory is automatically allocated and released by OS. No memory leak risk
	Teacher t;
	t.set_name("Confusius");
	t.set_age(30);
	t.set_gender("male");

	cout << t.get_name() << t.get_age() << t.get_gender() << endl;
	t.teach();
	
	// Instantiate a class array from the Heap. Instead, you have to allocate and release the heap memory manually!

	Teacher *ptr = new Teacher[2];
	if(ptr == NULL)
	{
		cout << "Block memory allocation fails!";
	}
	
	ptr->set_name("T0");
	ptr->set_age(40);
	ptr->set_gender("Male");

	(ptr + 1)->set_name("T1");
	(ptr + 1)->set_age(41);
	(ptr + 1)->set_gender("Female");
	
	for(int i(0); i < 2; i++)	
	{
		cout << (ptr + i)->get_name() << (ptr + i)->get_age() << (ptr + i)->get_gender() << endl;	
	}

	// free up the allocated heap memory to avoid memory leakage!
	delete[] ptr;
	ptr = NULL;

	return 0;
}
