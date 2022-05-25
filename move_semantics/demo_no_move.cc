// C++ program without declaring the
// move constructor
#include <iostream>
#include <vector>
using namespace std;

// Move Class
class Move {
private:
	// Declaring the raw pointer as
	// the data member of the class
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

	// Copy Constructor to delegated
	// Copy constructor
	Move(const Move& source)
		: Move{ *source.data }
	{

		// Copying constructor copying
		// the data by making deep copy
		cout << "Copy Constructor is called - "
			<< "Deep copy for "
			<< *source.data
			<< endl;
	}

	// Destructor
	~Move()
	{
		if (data != nullptr)

			// If the pointer is not
			// pointing to nullptr
			cout << "Destructor is called for "
				<< *data << endl;
		else

			// If the pointer is
			// pointing to nullptr
			cout << "Destructor is called"
				<< " for nullptr"
				<< endl;

		// Free the memory assigned to
		// data member of the object
		delete data;
	}
};

// Driver Code
int main()
{
	// Create vector of Move Class
	vector<Move> vec;

	// Inserting object of Move class
    // Create an temporary Move object by calling constructor
    // Copy it o the vec by calling Copy Constructor
	vec.push_back(Move{ 10 });

    // table doubling need copy the Move{10}
	vec.push_back(Move{ 20 });
	return 0;
}


/** Q: Copy Constructor vs Copy assignment operator
  * A: ref: https://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/
  * Copy Constructor allocate a new memory block while assignment operator requests no memory.
  * copy constructor creates a new object of the class while assignment operator does not create new
  * object.
  */
