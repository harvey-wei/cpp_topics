#ifndef ARRAY_H
#define ARRAY_H
/*
 The the class can be referenced with the definition of the class itself!
*/
class Array 
{
public:
	Array(int len);
	~Array();
	void set_len(int len);
	int get_len();
	Array* print_info(); // the class name can occur in the body of the same class!!!
private:
	int len; // len is short for length!!!
};
#endif
