//
//  iterator.cpp
//  cpp_basic_xcode
//
//  Created by Harvey MAO on 2021/10/29.
//

// C++ program to demonstrate iterators
  
#include <iostream>
#include <vector>
using namespace std;

int main_as()
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

    return 0;
}




int main_xx()
{
    // Declaring a vector
    vector<int> v = { 1, 2, 3 };
  
    // Declaring an iterator
//    vector<int>::iterator i;
  
    int j;
  
    cout << "Without iterators = ";
      
    // Accessing the elements without using iterators
    for (j = 0; j < 3; ++j)
    {
        cout << v[j] << " ";
    }
  
    cout << "\nWith iterators = ";
      
    // Accessing the elements using iterators
//    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        // can be dereferenced as a rvalue.
        cout << *i << " ";
    }
  
    // Adding one more element to vector
    v.push_back(4);
  
    cout << "\nWithout iterators = ";
      
    // Accessing the elements without using iterators
    for (j = 0; j < 4; ++j)
    {
        cout << v[j] << " ";
    }
  
    cout << "\nWith iterators = ";
      
    // Accessing the elements using iterators
    // iterator also supports legal arithmetic.
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
  
    return 0;
}
