#include "gl_framework.h"
#include <sstream>
using namespace glmock;

ExceptionErrorCallback::ExceptionErrorCallback()
{
}

ExceptionErrorCallback::~ExceptionErrorCallback()
{
	if(!mErrors.empty()) {
		CommandError* errors = new CommandError[mErrors.size()];
		for(size_t i = 0; i < mErrors.size(); ++i) {
			memcpy(&errors[i], &mErrors[i], sizeof(CommandError));
		}

		throw MockException(errors, mErrors.size());
	}
}

void ExceptionErrorCallback::OnCommandNotCalled(const ICommand* command)
{
	CommandError cmd;
	strcpy_s(cmd.Command, 50, typeid(*command).name());
	strcpy_s(cmd.Error, 128, "Command not called");
	mErrors.push_back(cmd);
}

void ExceptionErrorCallback::OnBadParameter(const ICommand* command, const char* name, const char* expected, const char* actual)
{
	std::stringstream ss;
	ss << "Fuction: " << name << " was called with the wrong parameters. Expected: " << expected << " but was: " << actual;

	CommandError cmd;
	strcpy_s(cmd.Command, 50, typeid(*command).name());
	strcpy_s(cmd.Error, 128, ss.str().c_str());
	mErrors.push_back(cmd);
}

void ExceptionErrorCallback::OnBadFunctionCalled(const ICommand* command, const char* actual)
{
	std::stringstream ss;
	ss << "Expected function: " << typeid(*command).name() << " but was: " << actual;

	CommandError cmd;
	strcpy_s(cmd.Command, 50, typeid(*command).name());
	strcpy_s(cmd.Error, 128, ss.str().c_str());
	mErrors.push_back(cmd);
}

GLFramework* __instance = 0;
GLFramework::GLFramework()
	: mErrorCallback(&mDefaultErrorCallback)
{
	__instance = this;
}

GLFramework::~GLFramework()
{
	__instance = 0;
	if(mCommands.size() > 0) {
		// Not all commands where invoked!!!
		while(!mCommands.empty()) {
			ICommand* cmd = mCommands.front();
			mErrorCallback->OnCommandNotCalled(cmd);
			mCommands.pop();
		}
	}
}

GLFramework& GLFramework::Get()
{
	return *__instance;
}

void GLFramework::RegisterErrorCallback(IErrorCallback* callback)
{
	mErrorCallback = callback;
}

GLDeleteTextures* GLFramework::glDeleteTextures(GLsizei n, const GLuint* textures)
{
	GLDeleteTextures* command = new GLDeleteTextures(n, textures);
	mCommands.push(command);
	return command;
}

GLTexImage2D* GLFramework::glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
			GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	GLTexImage2D* command = new GLTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
	mCommands.push(command);
	return command;
}

GLBindTexture* GLFramework::glBindTexture(GLenum target, GLuint texture)
{
	GLBindTexture* command = new GLBindTexture(target, texture);
	mCommands.push(command);
	return command;
}

GLGetError* GLFramework::glGetError()
{
	GLGetError* command = new GLGetError();
	mCommands.push(command);
	return command;
}

GLBlendFunc* GLFramework::glBlendFunc(GLenum sfactor, GLenum dfactor)
{
	GLBlendFunc* command = new GLBlendFunc(sfactor, dfactor);
	mCommands.push(command);
	return command;
}

void GLFramework::OnBadParameter(const ICommand* command, const char* paramName, const char* expected, const char* actual)
{
	__instance->mErrorCallback->OnBadParameter(command, paramName, expected, actual);
}

/*
void GLFramework::AddCommandError(ICommand* command, const char* error)
{
	CommandError cmderr;
	strcpy_s(cmderr.Command, 50, typeid(*command).name());
	strcpy_s(cmderr.Error, 128, error);
	mErrors.push_back(cmderr);
}
*/