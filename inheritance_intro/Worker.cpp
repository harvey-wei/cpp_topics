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
	cout << "The worker is now out of work" <<endl;
}
