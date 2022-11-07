#include "iostream"
using namespace std;
/*
In some cases, the programmer/developer can not determine how much memroy space should be assigned to the array. In order to deal with such a problem, the dynamically allocated heap is introduced!

What is meant by dynamically is that the size of the allocated memory space can be determined at run time instead of compile time! Recall that C++ is a static language which means that the type and number of data type(memory space size) must be determined at compile time! But instance from the heap is an execption!

*/

void func(int a, int b, int c)
{
    return;
}
int main()
{
	int n(0);
	cout << "Please Input an integer specifying the size of the array" << endl;
	cin >> n;

	//stick to the allocate, check , release and reassigned NULL
	int *ptr = new int[n];   //  ptr will point to the first element of the allocated heap space!  
	if(!ptr)
	{
		cout << "Allocation fails!" << endl;
	}

	for(int i(0); i < n; i++)
	{
		*(ptr + i) = i;
	}

	for(int i(0); i < n; i++)
	{
		cout << *(ptr + i) << endl;
	}

	delete [] ptr;
	ptr = NULL;


    func(1, 2, 3);

	return 0;
}
