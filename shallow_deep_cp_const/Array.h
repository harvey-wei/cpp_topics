#ifndef ARRAY_H
#define ARRAY_H
// the above preprocessing directives are used to avoid error message resulting from 
// multiple inclusion(furthermore, multiple definition!!!)
class Array 
{
	public:
		Array(int _count = 3);
		Array(const Array &arr);   // const reference to the object of the same class!!!
		~Array();
		// common interface 
		void set_count(int _count);
		int get_count();
		void print_addr();
		void print_arr();
	private:
		int m_int_count;
		int *m_int_ptr_Arr;
};
#endif
