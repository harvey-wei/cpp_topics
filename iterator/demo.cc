// C++ program to demonstrate iterators

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	// Declaring a vector
	vector<int> v = { 1, 2, 3 };

	// Declaring an iterator
	vector<int>::iterator i;

	int j;

	// Inserting element using iterators
	for (i = v.begin(); i != v.end(); ++i) {
		if (i == v.begin()) {
			i = v.insert(i, 5);
			// inserting 5 at the beginning of v
		}
    }

	// v contains 5 1 2 3

	// Deleting a element using iterators
	for (i = v.begin(); i != v.end(); ++i) {
		if (i == v.begin() + 1) {
			i = v.erase(i);
			// i now points to the element after the
			// deleted element
		}
	}

	// v contains 5 2 3

	// Accessing the elements using iterators
	for (i = v.begin(); i != v.end(); ++i) {
		cout << *i << " ";
	}

    const std::vector<int>::iterator it = v.begin();
    *it = 11;
    it = v.end(); // error: assignment of read-only variable ‘it’

	return 0;
}

/**  ref: https://www.geeksforgeeks.org/introduction-iterators-c/
  *  A: list, map, multimap, set and multiset support bidirectional iterators
  *  support equality/inequality, dereferencing, increment/decrement, and swappable but DON'T HAVE
  *  arithmetics!
  *  ref: https://www.geeksforgeeks.org/bidirectional-iterators-in-cpp/
  *
  *  B: vector and deque have random access iterators  which support all of bidirectional iterators
  *  and iterator arithmetics.
  *  ref: https://www.geeksforgeeks.org/random-access-iterators-in-cpp/
  */
