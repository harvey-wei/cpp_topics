#include "Worker.h"
#include "iostream"
using namespace std;
Worker::Worker()
{
	cout << "Worker()" <<endl;
}

Worker::~Worker()
{
	m_int_age =10;   // private member can be inherited but not be accessed!!
	m_str_name = "harvey";
	cout << "~Worker()" <<endl;	
}
void Worker::work()
{
	cout << "The worker is now out of work" <<endl;
}
