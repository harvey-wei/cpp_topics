#include "Array.h" // convenient for compiler to check!!!
#include "iostream"
using namespace std;

Array::Array(int _count)
{
	m_int_count = _count;	
	m_int_ptr_Arr = new int[_count];  // new can be used in constructor
	if (!m_int_ptr_Arr)
	{
		cout << "Allocation fails" <<endl;
		exit(0);  // exit from the program if fails
	}
	for(int i(0);i < m_int_count; i++)
	{
		m_int_ptr_Arr[i] = i;
	}
	cout << "Array(int _count)" << endl;
}
Array::Array(const Array &arr)   // const reference to the object of the same class!!!
// mnemonic: const reference to the object of the same class!!!!
{
	m_int_count = arr.m_int_count;
	/* m_int_ptr_Arr = arr.m_int_ptr_Arr;  // shallow copy!!! points to the same memory space */
	m_int_ptr_Arr = new int[m_int_count];  // allocate different memory !!!
	for (int i(0); i < m_int_count; i++)
	{
		m_int_ptr_Arr[i] = arr.m_int_ptr_Arr[i];  // pointer name act as array name!	
		/* *(m_int_ptr_Arr + i) = *(arr.m_int_ptr_Arr + i) */
	}
	
	cout <<"Array(const Array &arr) " <<endl;
}
Array::~Array()
{
	delete []m_int_ptr_Arr; // do not forget to release the memory to avoid memory leakage!!!
	m_int_ptr_Arr = NULL;  // redirect the pointer to NULL(0)
	cout << "~Array()" <<endl;
}
void Array::set_count(int _count)
{
	m_int_count = _count;
}
int Array::get_count()
{
	return m_int_count;
}

void Array::print_addr()
{
	cout << "Address of array" << m_int_ptr_Arr <<endl;
}

void Array::print_arr()
{
	for(int i(0); i < m_int_count; i++)
	{
		cout << m_int_ptr_Arr[i] << endl;
	}
}
