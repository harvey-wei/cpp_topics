#ifndef SHAPE_H
#define SHAPE_H
using namespace std;
class Shape 
{
	public:
		Shape();
		/* ~Shape(); */
		double cal_area();
		virtual ~Shape(); 
		// Recall virtual can only qualify destructor and member function!
		// Virtual can not modify the constructor
		// The derived class also will have a vitual ptr and 
		// Even if no virtual is prefixed to the destructor of the derived class
		// compiler will automaticllay add virtual keyword!!!
		/* virtual double cal_area(); */
		
};
// Size of object indicate how much memory the data member(including virtual pointer) take up!!
// Address of the object: the address of the first unit of object 
// Address of the data member: the address of the first unit of the data member
// When virtual occurs in the class, the virtual ptr will be inserted into the first block ofthe object 
#endif
