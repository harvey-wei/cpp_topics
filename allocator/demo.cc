#include <iostream>

/**
 * C++ program for illustration
 * of std::allocator() function
 */
#include <iostream>
#include <memory> // for std::allocator class

int main()
{

	// allocator for integer values
	std::allocator<int> myAllocator;

	// allocate space for five ints
	int* arr = myAllocator.allocate(5);

	// construct arr[0] and arr[3]
	// myAllocator.construct(arr, 100); // no longer allowed in C++20
	arr[0] = 100; // do this instead
	arr[3] = 10;

	std::cout << arr[3] << std::endl;
	std::cout << arr[0] << std::endl;

	// deallocate space for five ints
	myAllocator.deallocate(arr, 5);

	return 0;
}

/**
 * What is std::allocator() in c++?
 * Alloctor is object for encapsulating memory management.
 * It is used when you want to separate allocation and construction in two steps or when you want
 * to separate destruction and deallocation in two steps.
 *
 * Bear it in mind:
 * All of the STL Containers (vector, list, set, map, stack, queue, etc.) in c++ have a type
 * paramter Allocator which defaults to be std::allocator. The default allocator simpy uses
 * new and delete to obtain and release memory.
 *
 * https://medium.com/@terselich/1-a-guide-to-implement-a-simple-c-stl-allocator-705ede6b60e4
 * https://docs.ros.org/en/foxy/Tutorials/Advanced/Allocator-Template-Tutorial.html
 */
