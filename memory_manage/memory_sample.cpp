#include "iostream"
using namespace std;

int main()
{
	int *p = new int(20);  // you can initialize the newly allocated memory 
	int *q = new int[1000]; // q points to the first element of newly allocated 
	// check for p
	if (!p)                // Failure leads to the NULL 
	{
		cout << "The allocation fails" << endl;
		return 0;
	}
	q[0] = 10;  // access as array
	q[1] = 20;   

	cout << *p << endl;
	
	//release the memory from the Heap
	delete p;
	p = NULL;
	delete[] q;   
	// Note q points to the first int unit of allocated memory 
	// If [] is omitted, then only the first unit memory is freed up!!!

	return 0;
}	
