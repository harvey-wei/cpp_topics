/*
friend class can access the private and protected data and function member of other class where the class is  declared as friend!!!
In summary, friend has special privilege to access the data and function member.


Caveats about the use of friend!
1. No transitivity. Just like friends in real life, transitivity does not apply to friend relation in C++. For example, A is a friend of B, B is a friend of C, we can not infer that A is a friend of C/ 
2. Unidirectional! If A is a friend of B, B is not necessarily a friend of C!
3. Friend class and friend function can appear concurrently!
4. Friends violate the encapsulation !!!
*/
#include <iostream>
#include <string>
#include "Match.h"
using namespace std;

int main()
{
	Match m(6, 30, 45);
	m.test_time();

	return 0;
}
