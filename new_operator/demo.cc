// operator new example
#include <iostream>     // std::cout
#include <new>          // ::operator new
using namespace std;

struct MyClass {
  int data[100];
  MyClass() {std::cout << "constructed [" << this << "]\n";}
};

// Custom data type
struct cust
{
   int p;
   cust(): p(0) {}
   cust(int q) : p(q) {}
   ~cust()
   {
       std::cout << "Destroy cust object!" << std::endl;
   }
};

int main ()
{
    std::cout << "1: ";
    MyClass * p1 = new MyClass;
      // allocates memory by calling: operator new (sizeof(MyClass))
      // and then constructs an object at the newly allocated space

    std::cout << "2: ";
    MyClass * p2 = new (std::nothrow) MyClass;
      // allocates memory by calling: operator new (sizeof(MyClass),std::nothrow)
      // and then constructs an object at the newly allocated space

    std::cout << "3: ";
    new (p2) MyClass;
      // does not allocate memory -- calls: operator new (sizeof(MyClass),p2)
      // but constructs an object at p2

    // Notice though that calling this function directly does not construct an object:
    std::cout << "4: ";
    MyClass * p3 = (MyClass*) ::operator new (sizeof(MyClass));
      // allocates memory by calling: operator new (sizeof(MyClass))
      // but does not call MyClass's constructor

    delete p1;
    delete p2;
    delete p3;

    // Works fine, doesn’t require constructor
    cust* var1 = new cust;

    // Works fine, doesn’t require constructor
    cust* var2 = new cust();

    // Notice error if you comment this line
    cust* var = new cust(25);

    // We are using nothrow here.
    /* int *piValue = new(nothrow)int[999999999999999]; */
    int *piValue = new(nothrow) int[999999999999999];
    if(!piValue)
    {
        cout<<"Free memory is not available"<<endl;
    }
    else
    {
        cout<<"Free memory available"<<endl;
        delete []piValue;
    }

    std::cout << "Not throw the bac_alloc" << std::endl;

    return 0;
}

// Q: What does the new operator return?
// A: a pointer to the newly allocated storage space in the heap.
// In T* ptr = new T, the ptr is of type T*.
// https://stackoverflow.com/questions/2697892/what-is-return-type-of-new-in-c
// This is why std::shared_ptr is called shared pointer to contain the return values of new
// operator.
//  https://aticleworld.com/dynamic-memory-and-new-operator-c/
// https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/
// https://www.geeksforgeeks.org/exception-handling-c/
