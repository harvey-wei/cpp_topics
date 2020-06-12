#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/*
Function Name: division
Inputs: integer dividend, integer divisor
*/

int division(int dividend, int divisor)
{
	if(!divisor)
	{
		// throw a exception indicating "divisor can not be zero"
		throw string("Divisor should not be zero!!!");
		// recall that once an exception is thorow, all code following that will not execute!
	}

	return dividend / divisor;
}

int main()
{
	int dividend(0);
	int divisor(0);
	int remainder(0);
	
	cout << "Ipnut an integer as dividend" << endl;
	cin >> dividend;
	cout << "Enter an integer as divisor" << endl;
	cin >> divisor;

	try 
	{
		// protected code
		cout << division(dividend, divisor) << endl;
	}
	catch(string &e)   // what is thrown is assigned to e if both class types match!
	{
		cout << e << endl;	
	}

	return 0;
}
