#include "iostream"
using namespace std;
// The protected behaves in the similar way  to the private.
// Protected members is always accesible to sub-class even if protected downgrades to private when interiting on a private basis.
// In contrast, the private members are inaccessible to derived class irrespective of the inheriting mode!
// Friend functions have access to both protected and private members of one class, data members and member functions.
// We make the distinction between functons, member functions and friend functions.

//base class
class Parent
{
protected:
int id_protected;

};


// sub class or derived class or inherited class
class Child : public Parent
{
public:
void setId(int id)
{
	//child class is able to access the inherited
	// protected date members of base class

	id_protected = id;

}

void display_ID()
{
	cout << "id_protected is " << id_protected <<endl;

}
};
int main()
{
	Child obj1;
	obj1.setId(81);  // subobject set ID for parent objec  // subobject set ID for parent objectsy:t
	obj1.display_ID(); // () is compulsory
	return 0;
}
