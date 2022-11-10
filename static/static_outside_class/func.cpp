#include <iostream>
#include <string>
using namespace std;

static void func()
{
	cout << "Static Function is accessible within the file where it is defined only" << endl;
}

static int static_int = 100;
