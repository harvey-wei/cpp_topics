#include "iostream"
#include "string"
using namespace std;

int main()
{
	// different ways to concatenate strings!!!!
	string s1 = "hello";  // c-style initialization
	string s2("world");   // c++ style initialization
	string s3 = s1 + s2;  // concatenate two string variables
	string s4 = "hello" + s2; // concatenate string literal and string variables
	string s5 = "hello" + s2 + "world"; // legal
	/* string s6 = "hello" + "world";   // two string literal can not be joined via plus operator "+"; */

	// cout can be used for printing out the string literal and string variables directly 
	cout << s1 << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
		
	
	return 0;
}

