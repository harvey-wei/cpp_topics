/*
One of the advantages of C++ over C is Exception Handling. Exceptions are run-time anomalies or abnormal conditions that a program encounters during its execution. There are two types of exceptions: a)Synchronous, b)Asynchronous(Ex:which are beyond the program’s control, Disc failure etc). C++ provides following specialized keywords for this purpose.

Protected Code:
Code within a try/catch block is referred to as protected code!!!

One thing worth watching out is that the code following the point where the exception is thrown will not be executed!!

Common Exceptions:
1. array index goes beyond the range!
2. division by zero
3. memory is not sufficient,e.g. infinite loop where memory leakage occurs!!!

Q1: How does the exception relate to the polymorphism?
We can define exception as interface class(only contian pure virtual functions). Then, different types of exceptions can defined to be the sublcass of this interface class!Pure virtual functions can achieve run-time polymorphism!!
There two types of exceptions classes: Standard C++ Exception and User-defined Exception Class!
For more details on exceptions, refer to the blog posts at https://www.geeksforgeeks.org/exception-handling-c/ and https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm 

Q2: How to pair throw and catch?
Case 1: throw 1 --- catch(int), exception type is int
Case 2: throw 0.01----catch(double), exception type is of double!
Above cases are to catch the type of Exception not the value of what is thrown.

Case 3: throw classname(); (is needed)
Case 4: throw string("Divisor can not be zero!") 

Q3: Who handle the exception?
Functions/Methods can handle any exceptions they choose. If all callers are unable or not choose to handle the raised exceptions, the OS will kill the program without concrete descriptions, which is not what we want!

Q4:What is thrown and what is caught?
Throw an object of certain class such as int, double, string, and user-defined class object!!

catch the type of what is thrown (can further assign what is thrown to the variable) such as
throw IndexException()
catch(IndexException & e); an IndexException object is assigned to e!!!!!

throw 0.1
catch(double) or catch(double e)

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "Exception.h"
#include "IndexException.h"
using namespace std;

/**********************************************************************/
/* Exception Handling:
   1. Define a Exception class: printException and virtual destructor (Abstract Class)
   2. Define a IndexException which is publicly inherited from Exception*/
/*Key idea: the error or exceptiono that you can raise should be a  class which direcly or indirectly must be a class incluidng built-in type or class
for both python and C++*/
/**********************************************************************/

void test()
{
	/* throw 10; */
	/* throw 0.1; */  
	/* throw "Error"; */
	/* throw IndexException(); // throw a defined exception class object hence () is needed!! */
	throw string("Error");
}

int main()
{
	try
	{
		test();
	}
	/* catch(int)  // int match 10 or other integers, catch(int) can not catch double, then exception will be submitted to the caller at higher level or OS */
	/* catch(double &e) // What is thrown is assigned to reference e!! */

	/* catch(IndexException & e) */
	/* catch(Exception &e) */
    /* catch(...)// ellipsis  can catch all kinds of exceptions!*/
	catch(string & e)
	{
		/* cout << "exception" << endl; */
		/* cout << e << endl; */
		/* e.printException(); */
		cout << e << endl;
	}

	return 0;
}
