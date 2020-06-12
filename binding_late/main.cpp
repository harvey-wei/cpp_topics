#include <iostream>
#include <string>
using namespace std;

// Polymorphisim can be split into two types:
// Early Binding(Static Polymorphisim) of message to the implementation such as function/ operator overloading happens at compile-time!!
// Late Binding(Dynamic Polymorphisim) of message to the implementation such as pointer remaining to point one of a set of functions where the decision is made at run-time!!


double add(double m, double n)
{
	return m+n;
}

double sub(double m, double n)
{
	return m-n;
}

double mul(double m, double n)
{
	return m*n;
}

int main()
{
	double x,y;
	cout << "Type in two numbers" <<endl;
	cin >>x>>y;
	
	int task(0);
	do 
	{
	cout << "Enter task (1 = add, 2 = sub, 3 = mul)"<< endl;
	cin >> task;   // at run-time, late binding whereas overloading is determined at compile-time(early binding)
	}while(task < 1 || task >3);
	double (*ptr)(double, double);  // pointer to the function
	// late binding at run-time
	// decisions are not taken as to which function needs to be executed until run time, i.e. late bind the name of function to the right address in the memory!
	switch(task)
	{
		case 1:
			ptr = &add;
			break;
		case 2:
			ptr = &sub;
			break;
		case 3:
			ptr = &mul;
			break;
		default:
			cout << "no match" <<endl;
	}

	cout << "Result is " << (*ptr)(x,y) << endl;
	return 0;
}
