#ifndef FUNC_H
#define FUNC_H

// In order to declare a function as an inline function, you only need to put the keyword inline to the far 
// beginning of the function declaration 
inline int max(int a, int b, int c);
// inline function
// Like default values, you only need to add the inline keyword in declaration
// You are supposed to put the inline function definition in the header file. Otherwise, the compiler does not know what to insert the call-point when it is compiling the source files. Inserting the function definition into the call-sites during the compiling time separate the inline function from the standard function.

int max(int a, int b, int c)
{
	// store the maximum in a
	if(a < b)
	{
		a = b;
	}

	if(a < c)
	{
		a = c;
	}
	
	return a;
}
#endif
