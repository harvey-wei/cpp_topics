#include "main.h"
using namespace std;

int main()
{
	Array arr_1(10);
	Array arr_2(arr_1);  // Creation of arr_2 only call copy_constructor not the constructor!
	arr_1.print_arr();   // pointer is a variable storing the address of another 
	arr_2.print_arr();
	return 0;
}

