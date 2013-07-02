#include "gl_command.h"
#include <string>
using namespace glmock;

GLCommand::GLCommand(const char* name)
	: Name(mName)
{
	strcpy_s(mName, name);
}

GLCommand::~GLCommand()
{
}
