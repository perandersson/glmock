#include "exception.h"
using namespace glmock;

IMockException::IMockException(CommandError*& const errors, const unsigned int& count)
	: Errors(errors), Count(count)
{
}

/////////////////////////////////////////

MockException::MockException(CommandError* errors, unsigned int count) 
	: mErrors(errors), mCount(count), IMockException(mErrors, mCount)
{
}

MockException::~MockException()
{
	delete mErrors;
}
