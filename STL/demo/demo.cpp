#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

int main()
{

	/*
	vector class can automatically resize itself when being pushing or poppped!!
	Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

	Reference at https://www.geeksforgeeks.org/vector-in-cpp-stl/
	*/
	/*
	push_back() – It push the elements into a vector from the back
    pop_back() – It is used to pop or remove elements from a vector from the back.
	*/
	/* vector<int> vec;    // empty vector instance */
	/* vec.push_back(3);  //  insert 3 to the back of vec!!!!  index is 0 */
	/* vec.push_back(4);  //  index is 1 */
	/* vec.push_back(6);  //  index is 2 */

	/* vector<int>::iterator iter = vec.begin(); */
	/* cout << *(iter + 2) << endl; // 3th element of vector */
	/* vec.pop_back();    // delete the last element in the vector, */

	/*cout << "size:" << vec.size() << endl;    //  size = # of elements pushed into the original empty vector!*/
		
	/**/
	/*	traverse the vector  in the same fashion as the built-in array, python list indexing!, np.array indexing*/
	/**/

	/*cout << "Traverse by indexing operators!" << endl;*/
	/*for(int i(0); i < vec.size(); i++)  // index of vector starting from 0;*/
	/*{*/
	/*	cout << vec[i] << endl;*/			
	/*}*/
	
	/**/
	/*	Traverse the vector by iterators!*/	
	/*	Iterator has the similar syntax to pointer*/
	/*	Hence, *iterator returns the value at that iterator!!*/
	/**/

	/*vector<int>::iterator iter(vec.begin());*/
	/* cout << *iter << endl; */

	/*cout << "Traversal by iterators" << endl;*/
	/*// iterating from vec.begin() and stop when reaching vec.end()*/

	/*for(; iter != vec.end(); iter++)*/
	/*{*/
	/*	cout << *iter << endl;*/
	/*}*/

	/**/
	/*front() – Returns a reference to the first element in the vector*/
	/*back() – Returns a reference to the last element in the vector*/
	/**/

	/*cout << vec.front() << endl;*/
	/*cout << vec.back() << endl;*/


	// list is also sequential container!
	// one list node consists of data field and address field!
	/*
		Lists are sequence containers that allow non-contiguous memory allocation.
		As compared to vector, list has slow traversal, but once a position has been found, insertion and deletion are quick. 
		Normally, when we say a List, we talk about doubly linked list. 
		For implementing a singly linked list, we use forward list.
	*/

	list<int>  list1;
	list1.push_back(4);
	list1.push_back(7);
	list1.push_back(10);

	// you can not access the  list element by indexing because non-contiguous memory allocation!!!
	/* for(int i(0); i < list1.size(); i++) */
	/* { */
		/* cout << list1[i] << endl;// [] can not access list elements! */
	/* } */
	
	// Traverse the list by iterators!!!!!	
	/* list<int>::iterator iter_list1 = list1.begin();   // list1.begin + i points tothe i+1th elements */
	/* for(; iter_list1 != list1.end(); iter_list1 ++) */
	/* { */
		/* cout << *iter_list1 << endl; */	
	/* } */

	/* list<int>::iterator iter1 = list1.begin(); */
	/* cout << *(iter1 + 1) << endl; */  //no iter1 + 1 for list but work for vector!

	/*
	Maps are associative containers that store elements in a mapped fashion. 
	Each element has a key value and a mapped value. 
	No two mapped values can have same key values.		
	*/
	// Create an empty map
	map<int, string> m;  // int is type of key, string is the type of value

	// create a pair of key and value
	pair<int, string> p1(3, "hello"); // A map consists of a certain number of 
	pair<int, string> p2(6, "world");
	pair<int, string> p3(8, "Beijing");
	// insert the pair of key and value to the map!
	/* m.push_back(p1); */ //no push_back for map
	m.insert(p1);
	m.insert(p2);
	m.insert(p3);

	// Traverse by key
	/* cout << m[3] << endl; */
	/* cout << m[6] << endl; */
	
	// Traverse the map by iterators
	// Note that iterators can be applied to all kinds of standard templates!
	map<int, string>::iterator iter_map(m.begin());
	for(; iter_map != m.end(); iter_map ++)
	{
		/* cout << *iter_map << endl; */
		cout << iter_map->first << endl;  // iter_map-first is key
		cout << iter_map->second << endl;  // iter_map->second is value
	}

	map<string, string> m_1; // key can be a string
	pair<string, string> p_1("H", "Hello");
	pair<string, string> p_2("W", "World");
	pair<string, string> p_3("B", "Beijing");

	m_1.insert(p_1);
	m_1.insert(p_2);
	m_1.insert(p_3);
	cout << m_1["H"] << endl;
	

	return 0;
}
