#ifndef MY_ARRAY_H
#define MY_ARRAY_H
#include <iostream>
#include <string>
using namespace std;
//!!!!!!
/*
In contrast to regular class, member functiuo of class template must positioned in the file where class is declared, i.e. .h file!1
*/
/*
For each member funciton definition outside the class, you should note:
1. template <parameter list> should be placed before each member function definition
2. ClassName must be followed by a pair of angle bracket enclosing the parameter such as ClassName<T, U, S>::function_name()(Order of the parameters should match the parameter list in template part!)

If you define member function inside the class, it eliminates the need to do the above two things!
*/

/*
template <parameter list> must be put above the class Name {};
*/
template <typename T, int KSize, int KVal>
class My_Array
{
	public:
		My_Array();
		virtual ~My_Array();  // It is good practice to declare destructor as virtual
		void display();
	
	private:
		T * m_ptr_Arr;	
};


template <typename T, int KSize, int KVal>
My_Array<T, KSize, KVal>::My_Array()
{
	m_ptr_Arr = new T[KSize]; // An array of objects of T type!!
	for(int i(0); i < KSize; i++)
	{
		*(m_ptr_Arr + i) = KVal; // m_ptr_Arr[i] = KVal is also legal
	}

}


template <typename T, int KSize, int KVal>
My_Array<T, KSize, KVal>::~My_Array()
{
	// relese the heap space 
	delete m_ptr_Arr;
	m_ptr_Arr = nullptr;
}

template <typename T, int KSize, int KVal>
void My_Array<T, KSize, KVal>::display()
{
	for(int i(0); i < KSize; i++)
	{
		cout << m_ptr_Arr[i] << endl;
	}
}
#endif
