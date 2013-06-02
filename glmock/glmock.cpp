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
			ICommand* cmd = mCommands.front();
			AddCommandError(cmd->GetName(), "Expected to be called but wasn't");
			mCommands.pop();
		}
	}

	if(!mErrors.empty()) {		
		std::stringstream ss;
		for(size_t i = 0; i < mErrors.size(); ++i) {
			ss << mErrors[i]->Command << " => " << mErrors[i]->Error << std::endl;
		}

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

