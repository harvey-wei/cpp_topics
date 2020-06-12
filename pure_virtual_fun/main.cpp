#include "main.h"
/*
C++ Program to demonstrate the use of  pure virtual function!
*/
int main()
{
	/* Person person("Jim");  // abstract type can not be instantiated */
	/* Worker worker("John", 12); // abstract type can not be instantiated */
	Dustman dustman("Bob", 25);
	dustman.work();

}
