#include "iostream"
using namespace std;

class Geeks 
{
	//Access specifier
	public:

	//Date Members(properties)
	string geek_name;

	//member functions(method)
	void print_name()
	{
		cout << "Geekname is:" << geek_name << endl;
	}

}; // class definition must end with semicolon!!!
// in order not to forget the ; you can type class ClassName {}; at first!!!
int main()
{
	// define an object of class geeks
	Geeks geek_1;

	// Accessing date member
	geek_1.geek_name = "harvey";

	// Accessing member function
	geek_1.print_name();

return 0;
}
