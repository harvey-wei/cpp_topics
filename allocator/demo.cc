#include <iostream>

/**
 * C++ program for illustration
 * of std::allocator() function
 */
#include <iostream>
#include <memory> // for std::allocator class

class A
{
    public:
        A()
        {
            std::cout << "construct A!" << std::endl;
        };

        ~A()
        {
            std::cout << "destruct A!" << std::endl;
        }
};


int main()
{

	// allocator for integer values
	std::allocator<int> myAllocator;

	// allocate space on heap for five ints without constructing objects.
	int* arr = myAllocator.allocate(5);

	// construct arr[0] and arr[3]
	// myAllocator.construct(arr, 100); // no longer allowed in C++20
	arr[0] = 100; // do this instead
	arr[3] = 10;

	std::cout << arr[3] << std::endl;
	std::cout << arr[0] << std::endl;

	// deallocate space on heap for five ints
	myAllocator.deallocate(arr, 5);

    /* A* a = (A*) ::operator new(sizeof(A)); */
    /* a->(A::A)(); */
    /* a->~A(); */
    /**/
    /* if (a != 0) */
    /* { */
    /*     a->~A(); */
    /*     ::operator delete(a); */
    /* } */

	return 0;
}

/**
 * What is std::allocator() in c++?
 * Alloctor is object for encapsulating memory management.
 * It is used when you want to separate allocation and construction in two steps or when you want
 * to separate destruction and deallocation in two steps.
 *
 * Where is std::allocator() allocate memory?
 * std::allocator allocates from the free store, which is often called the heap because that is
 * the data structure that is typically used to implement it.
 * Ref: https://stackoverflow.com/questions/44741914/does-the-std-allocator-dynamically-allocate-memory-on-the-heap-does-it-safely-d
 *
 * Bear it in mind:
 * All of the STL Containers (vector, list, set, map, stack, queue, etc.) in c++ have a type
 * paramter Allocator which defaults to be std::allocator. The default allocator simpy uses
 * new and delete to obtain and release memory.
 *
 * allocatation vs construction and deallocation vs destruction
 * The purpose of the allocator is to allocate raw memory without construction of objects,
 * as well as simply deallocate memory without the need to destroy them,
 *
 * https://medium.com/@terselich/1-a-guide-to-implement-a-simple-c-stl-allocator-705ede6b60e4
 * https://docs.ros.org/en/foxy/Tutorials/Advanced/Allocator-Template-Tutorial.html
 * https://www.codeproject.com/Articles/4795/C-Standard-Allocator-An-Introduction-and-Implement
 */
