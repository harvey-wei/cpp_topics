#include <iostream>
#include <cmath>
using namespace std;

/*
   Q: How to initialize the SmartPointer?
   A: pass an address of data type/class or array of data type/ calss to it. Hence,
   The address is returned by new operator. You need to define the constructor!

   Q: How to apply arrow operator and asterisk operator on the smart pointer?
   A: As the smart pointer is a custom class, you must overload the * and ->. Note that the dot operator can not be overloaded. -> must
   return the reference to the smart pointer since -> can only be called on pointer. A reference to
   pointer is the best choice. Don't return the smart pointer iteself!

   * must return what the smart pointer points to. Therefore, you are better off returning the
   reference to what the smart pointer points to.

*/

template<typename T>
class SmartPointer_
{
	private:
		T* ptr;
	public:
		SmartPointer_(T* p = nullptr) : ptr(p) {}

		~SmartPointer_()
		{
			delete ptr;
		}

		// overload array operator to return the raw pointer
		T*& operator->(){ return ptr;}

		// overload asterisk operator to return reference to the object pointed by ptr
		T& operator*(){ return *ptr;}
};

template<class T>
class SmartPointer
{
    private:
        // use to store the address returned by new operator when
        // initialize the smart pointer.
        T *ptr;

    public:
        // constructor to initialize the ptr with the address given by new.
        SmartPointer(T* p = nullptr): ptr(p) {};

        // Destructor to de-allocate the memory pointed to by ptr's address value.
        ~SmartPointer()
        {
            /* Free up the memory pointed to by address held by ptr. */
            delete ptr;
            std::cout << "The memory is disposed of! " << std::endl;
        }

        // Overload arrow operator and make it return reference to ptr.
        T*& operator->()
        {
            return ptr;
        }

        // Overload asterisk operator and make it return reference to what is
        // pointed by ptr
        T& operator*()
        {
            return *ptr;
        }
};

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

 double calc_dist()
{
    SmartPointer<Point> smart_ptr = new Point(10, 222);
    std::cout << "x: " << smart_ptr->x << std::endl;
    std::cout << "y: " << (*smart_ptr).y << std::endl;

    return  sqrt(double(smart_ptr->x * smart_ptr->x + smart_ptr->y * smart_ptr->y));
}

int main()
{
    double dist = calc_dist();
    std::cout << "The length of the vector is " << dist << std::endl;
}
