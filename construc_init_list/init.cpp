#include "iostream"
#include "string"
#include "Student.h"
using namespace std;

int main()
{
	Student stu;
	Student * p = new Student;
	if (!p)
	{
		cout << "automatically allocated fails" <<endl;
	}
	delete p;
	Teacher t1(2);   // num of student is not set as default so you should specify!!!
	Teacher t2(10,"mary",35);
	cout << "The name of Teacher is " << t1.get_name() <<endl;	
	cout << t2.get_name() << " " << t1.get_age()<< " " << t1.get_num_stu()<< endl;

	/* const int a;  //  const variable must be initialized! */
	/* a = 10; */
	/* cout << a <<endl; */

	Circle cir(1, 10);
	cout << "The area of the circle is " << cir.get_area() << endl;

	return 0;
}

