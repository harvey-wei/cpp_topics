#include "iostream"
using namespace std;

class Circle
{
	public:
		double radius;
		
		double compute_radius() // it can access the radius in any case!
		{
			return 3.14 * radius * radius;	
		}
};

int main()
{
	Circle obj_cir;
	obj_cir.radius = 10.10;
	// accessing public date member outside the class body
	cout << "Radius is " << obj_cir.radius <<endl;
	/* cout << "Area is " << obj_cir.compute_radius << endl; // parentheses must be present!!! */
	cout << "Area is " << obj_cir.compute_radius() << endl;
return 0;
// date member radius and compute_radius are public to everyone such that they can be accessed from outside the class body!:wq
}
