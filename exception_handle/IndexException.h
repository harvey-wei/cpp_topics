#ifndef INDEX_EXCEPTION_H
#define INDEX_EXCEPTION_H
#include "Exception.h"

class IndexException : public Exception
{
	public:
		virtual void printException();  // run-time polymorphism!!
};

#endif
