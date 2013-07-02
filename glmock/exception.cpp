#include "exception.h"
using namespace glmock;

IValidationException::IValidationException(CommandError*& const errors, const unsigned int& count)
	: Errors(errors), Count(count)
{
}

MockEngineNotInitializedException::MockEngineNotInitializedException()
{
}

MockEngineNotInitializedException::~MockEngineNotInitializedException()
{
}
