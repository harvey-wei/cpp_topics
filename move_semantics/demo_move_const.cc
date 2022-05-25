// C++ program with declaring the
// move constructor
#include <iostream>
#include <vector>
using namespace std;

// Move Class
class Move {
private:
	// Declare the raw pointer as
	// the data member of class
	int* data;

public:

	// Constructor
	Move(int d)
	{
		// Declare object in the heap
		data = new int;
		*data = d;
		cout << "Constructor is called for "
			<< d << endl;
	};

	// Copy Constructor
	Move(const Move& source)
		: Move{ *source.data }
	{

		// Copying the data by making
		// deep copy
		cout << "Copy Constructor is called -"
			<< "Deep copy for "
			<< *source.data
			<< endl;
	}

	// Move Constructor
    // The key to move constructor is copy pointer in place of value and null-out the input pointer to temporary
    // data.
	Move(Move&& source)
		: data{ source.data }
	{
        // data gets the memory address of *source.data
        // not the value stored in address held by source.data
		cout << "Move Constructor for "
			<< *source.data << endl;
		source.data = nullptr;
	}

	// Destructor
	~Move()
	{
		if (data != nullptr)

			// If pointer is not pointing
			// to nullptr
			cout << "Destructor is called for "
				<< *data << endl;
		else

			// If pointer is pointing
			// to nullptr
			cout << "Destructor is called"
				<< " for nullptr "
				<< endl;

		// Free up the memory assigned to
		// The data member of the object
		delete data;
	}
};

// Driver Code
int main()
{
	// Vector of Move Class
	vector<Move> vec;

	// Inserting Object of Move Class
    // constructor and then move constructor
	vec.push_back(Move{ 10 });

    // Note that push_back and emplace_back have no difference
    // sine move constructor is defined !
	vec.push_back(Move{ 20 });

    /* `push_back(std::move())` or `emplace_back(std::move())` where std::move() returns a rvalue reference so that the `move constructor` is called. */
    /* The emplace_back can also accept the constructor arguments */

    /* Move& a = Move(10); */
	return 0;
}

/** Object_name(Object_name&& obj)
   : data{ obj.data }
    {
       // Nulling out the pointer to the temporary data
       // obj.data is a pointer.
       obj.data = nullptr;
    }

    Q: What is meant by double ampersands?
    A: An rvalue reference is formed by placing an && after some type.

    An lvalue reference is formed by placing an & after some type.

    A a;
    A& a_ref1 = a;  // an lvalue reference
    A&& a_ref2 = a;  // an rvalue reference

    https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2027.html

    A&  a_ref3 = A();  // Error! A() is an temporary object, rvalue!
    A&& a_ref4 = A();  // Ok to bind a temporary object

     std::vector<std::string> vec;
     vec.emplace_back(std::string("Hello")); // moves
     std::string s;
     vec.emplace_back(s); //copies
     https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back

  */
