#include <iostream>
using namespace std;

class Test
{
	public:
		//constructor
		Test(int x = 0, int y = 0)
		{
			this->x = x;
			this->y = y;
		}

		// Returning a reference is more convenient than pointer!
		// The returned reference can be used to chain function calls on a single object!
		Test & set_x(int a) 
		{
			x = a;
			return *this;
		}

		Test & set_y(int b) 
		{
			y = b;
			return *this;
		}

		void print_info()
		{
			cout << "x = " << x << "y = " << y <<endl;
		}

	private:
		int x;
		int y;
};

int main()
{
	Test obj(5, 6);

	obj.set_x(10).set_y(30);

	obj.print_info();

	return 0;
}
