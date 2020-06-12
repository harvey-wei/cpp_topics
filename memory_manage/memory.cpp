#include "iostream"
using namespace std;
// Topic: Memory management
// We can accomplish what dynamic array does by instantiate a block of memory from the heap!~
//

int main()
{
	int * p = new int;   // new is operator for allocating memory from Heap!!
	// Make sure that the type on both side of the assignment are the same
	// check if the allocation is successful
	// NULL is constant meaning addressing no object in the memory.
	if (p == NULL) // Note that == is logical equality
	{
		cout << "Allocation of memory failed" << endl;
		return 0;
	}

	int *q = new int;
	if (q == NULL)
	{
		cout << "Allocation of memory failed" << endl;
		return 0;
	}

	*p = 10;
	*q = 21;
	cout << (*p)*(*q) << endl;
	//Do not forget to release the memory on time
	//Do not forget to assign the NULL to the pointer whose value has been
	//freed up, in order to avoid the second-time call !
	delete p;
	p = NULL; //avoid being wrongly referenced 
	delete q;
	q = NULL;

	// request(=ask for) block of memory from the heap
	int n(5); // the number of elements in the block
	int * pb = new int[n];  // pb points to the first element in the allocated bolck memory(similar to dynamc)

	//check for the pointer variable produced by new
	/* if (pb == NULL) */
	if (!pb) // !pb equivalent to pb == NULL denn NULL = 0
	{
		cout << "Allocation of memory fails" << endl;
	}

	for (int i(0); i < n; i++)
	{
		*(pb + i) = i*i;
		cout << *(pb + i) <<endl;
	}

	cout << "The value of NULL" << NULL << endl;

	// release the allocated block of memory
	delete[] pb;   // [] is mandatory for freeing up the block of memory. Otherwise, only the first element of the block of memory is released!j
	pb = NULL;
	

	double * ptr_db = new double(101);
	if(!ptr_db)
	{
		cout << "Fail to allocate" <<endl;
	}

	cout << "The object to which the ptr_db points " << *ptr_db << endl;

	delete ptr_db;
	ptr_db = NULL;

    return 0;
}
