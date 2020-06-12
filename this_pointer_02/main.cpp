#include "main.h"
using namespace std;

int main()
{
	Array arr1(10);
	arr1.print_info()->set_len(5);  // print_info() return this pointer!!!!
	cout << "the address of object "<< endl << &arr1 <<endl;
	/* cout << "len = " << arr1.get_len() <<endl; */
	// this is the address of the object to whcih this points!!!!
	// For different objects of the same class, the values of this pointer are distinct!!
	
}
