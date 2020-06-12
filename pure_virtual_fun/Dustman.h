#ifndef DUSTMAN_H
#define DUSTMAN_H
#include "Worker.h"
#include "Person.h"
#include <string>
using namespace std;

class Dustman : public Worker
{
	public:
		Dustman(string _name, int _age);
		~Dustman() {}

		// The concretized pure virtual function should be re-declared as non-pure virtual function agian!
		virtual void work(); //  =0 is deleted. You should define the body!!!
};

#endif 
