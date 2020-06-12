#include "iostream"
#include "Person.h"
#include "Worker.h"
using namespace std;

int main()
{
	Worker *p = new Worker();
	if(!p)
	{
		cout << "" <<endl;
	}
	p->m_str_name = "Jim";
	p->m_int_age = 20;
	p->eat();
	p->m_int_salary = 2000;
	p->work();

	Worker worker_1;
	worker_1.m_str_name = "Kevin";
	worker_1.m_int_age = 23;
	worker_1.m_int_salary = 20000;
	worker_1.eat();
	worker_1.work();
	delete p;
	p = NULL;


}
