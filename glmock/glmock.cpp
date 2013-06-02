#include "glmock.h"
using namespace glmock;

namespace {
	GLMock* _instance;
}

GLMockException::GLMockException(std::string& message) : mMessage(message) 
{
}

GLMockException::~GLMockException()
{
}

std::string GLMockException::GetMessage()
{
	return mMessage;
}

GLMock::GLMock()
{
	_instance = this;
}

GLMock::~GLMock()
{
	_instance = 0;

	if(mCommands.size() > 0) {
		// Not all commands where invoked!!!
		while(!mCommands.empty()) {
			AddCommandError("", "");
		}
	}

	if(!mErrors.empty()) {		
		std::stringstream ss;
		throw GLMockException(ss.str());
	}
}

GLMock& GLMock::Get()
{
	return *_instance;
}

GLDeleteTextures* GLMock::glDeleteTextures()
{
	GLDeleteTextures* command = new GLDeleteTextures();
	mCommands.push(command);
	return command;
}

void GLMock::AddCommandError(const char* command, const char* error)
{
	CommandError* cmderr = new CommandError;
	cmderr->Command = command;
	cmderr->Error = error;
	mErrors.push_back(cmderr);
}

