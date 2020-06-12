//#include "Person.h"
#include "Worker.h"

int main()
{
	Worker *p = new Worker();
	/* p->m_str_name = "Jim"; */
	/* p->m_int_age = 20; */
	p->eat();
	p->m_int_salary = 2000;
	p->work();
	p->m_int_age = 100;  // after inheriatnce 
	p->m_int_height;  
	p->m_str_name;
	/* Worker worker_1; */
	/* worker_1.m_str_name = "Kevin"; */
	/* worker_1.m_int_age = 23; */
	/* worker_1.m_int_salary = 20000; */
	/* worker_1.eat(); */
	/* worker_1.work(); */

	Person person;
	/* person.m_str_name = "Merry"; */
	/* person.m_int_age = 100; */
	person.eat();
}
