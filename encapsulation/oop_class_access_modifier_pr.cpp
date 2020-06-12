#include "iostream"
using namespace std;

class Circle
{
	private:
		double radius;
		double compute_circumferance()
		{
			return 2 * 3.14 * radius; 
		}
		
	public:
		double compute_radius() // it can access the radius in any case!
		{
			// member function can access private 
			// date member radius 
			cout << "radius is " << radius << endl; 
			cout << "circumference is" << compute_circumferance() << endl;
			return 3.14 * radius * radius;	
		}
};

int main()
{
	Circle obj_cir;
	/* obj_cir.radius = 10.10; */
	// accessing public date member outside the class body
	/* cout << "Radius is " << obj_cir.radius <<endl; */
	/* cout << "Area is " << obj_cir.compute_radius << endl; // parentheses must be present!!! */
	cout << "Area is " << obj_cir.compute_radius() << endl;
	/* cout << "circumference is " << obj_cir.compute_circumferance() << endl; // compute_circumference is declared private !!! */
return 0;
// In this program, the radius is declared private, which can be accessed by member function with the same class
// or by friend function !!!!
}
