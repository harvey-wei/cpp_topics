/*
Just like variables, objects also when declared as static persist in the memory till the lifetime of program
*/

// Program to demonstrate the use of  static object of the class!

#include <iostream>
using namespace std;

class Kitty
{
	private:
		int i = 0;

	public:
		Kitty()
		{
			cout << "Construction!" << endl;
		}
		
		~Kitty()
		{
			cout << "Destruction!" << endl;
		}
};

int main()
{
	static Kitty obj;

	cout << "The main terminates!" << endl;

	return 0;
}

/*As you can see from the output on the screen,  Now the destructor is invoked after the end of main. This happened because the scope of static object is through out the life time of program.*/
