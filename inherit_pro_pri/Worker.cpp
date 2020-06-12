#include "Worker.h"
#include "iostream"
using namespace std;
Worker::Worker()
{
	cout << "Worker()" <<endl;
}

Worker::~Worker()
{
	cout << "~Worker()" <<endl;	
}
void Worker::work()
{
	m_int_age =10;   // private member can be inherited but not be accessed!!
	m_str_name = "harvey";
	m_int_height = 178;  // m_int_height is a private member of base class!!!
	cout << "The worker is now out of work" <<endl;
}
