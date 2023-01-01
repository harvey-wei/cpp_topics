// C++ program to illustrate the placement new operator
#include<iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


class Complex
{
private:
    double re_, im_;
public:
    // Constructor
    Complex(double re = 0, double im = 0): re_(re), im_(im)
    {
        cout << "Constructor : (" << re_
             << ", " << im_ << ")" << endl;
    }

    // Destructor
    ~Complex()
    {
        cout << "Destructor : (" << re_ << ", "
             << im_ << ")" << endl;
    }

    double normal()
    {
        return sqrt(re_*re_ + im_*im_);
    }

    void print()
    {
        cout << "|" << re_ <<" +j" << im_
             << " | = " << normal() << endl;
    }
};


int main()
{
	// initial value of X
	int X = 10;

	cout << "Before placement new :" << endl;
	cout << "X : " << X << endl;
	cout << "&X : " << &X << endl;

	// Placement new changes the value of X to 100 and return a pointer to the same type.
	int *mem = new (&X) int(100);

	cout << "\n After placement new :" << endl;
	cout << "X : " << X << endl;
	cout << "mem : " << mem << endl;
	cout << "&X : " << &X << endl;


    // buffer on stack
    unsigned char buf[sizeof(int)*2] ; // buf is the pointer to unsigned char (one byte)

    // placement new in buf
    int *pInt = new (buf) int(3);

    int *qInt = new (buf + sizeof (int)) int(5);  // sizeof(int) return the size in byte of an int
    int *pBuf = (int*)(buf+0) ;
    int *qBuf = (int*) (buf + sizeof(int)); // Note that buf is the pointer to unsigned char (1 byte)

    cout << "Buff Addr             Int Addr" << endl;
    cout << pBuf <<"             " << pInt << endl;
    cout << qBuf <<"             " << qInt << endl;
    cout << "------------------------------" << endl;
    cout << "1st Int             2nd Int" << endl;
    cout << *pBuf << "                         "
         << *qBuf << endl;


    // new can also takes the address on heap but you need to delete it manually
    int* ptr_heap = new int(100);
    int* ptr = new (ptr_heap) int(999);

    std::cout << "int at ptr_heap " << *ptr_heap << std::endl;
    std::cout << "ptr_heap: " << ptr_heap << std::endl;
    std::cout << "ptr     : " << ptr << std::endl;

    delete ptr;


    /*
       Buffer on stack;
    */
    const int buffer_size = 100;
    unsigned char buffer[100];

    Complex* pc = new Complex(4.2, 5.3);
    Complex* pd = new Complex[2];  // array of 2 complex object heap memory

    Complex* pe = new (buffer) Complex(2.6, 3.9);

    // use objects
    pc -> print();
    pd[0].print();
    pd[1].print();
    pe->print();

    // Release objects
    // calls destructor and then release memory
    delete pc;

    // Calls the destructor for object pd[0]
    // and then release memory
    // and it does same for pd[1]
    delete [] pd;

    // No delete : Explicit call to Destructor.
    pe->~Complex();

	return 0;
}

/**
 * Ref: https://www.geeksforgeeks.org/placement-new-operator-cpp/
 * What does the normal new operator do?
 * Two things: Allocate memory on heap and call the constructor of class to construct an object in
 * the allocated heap memory.
 *
 * You need to note the difference between allocation and construction, deallocation and
 * destruction. All of those four operations take time!
 *
 * What does the placement new operator in c++ do?
 * It can receive a pre-allocated memory (it can be on stack or heap) and construct an object in the passed
 * memory. If the pre-allocated memory is on stack, there is no need to delete the memory since the
 * compiler knows when to delete it and will handle the deallocation of the memory automatically.
 *
 */
