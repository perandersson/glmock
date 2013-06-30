#include "gl_framework.h"
#include <sstream>
#include <map>
#include <sstream>
#include <string>

#include "command/glDeleteTextures.h"
#include "command/glBindTexture.h"
#include "command/glTexImage2D.h"
#include "command/glBlendFunc.h"
#include "command/glGetError.h"
#include "command/glGenTextures.h"
#include "command/glFlush.h"

#include "command/glew/glUseProgram.h"
using namespace glmock;

ValidationException::ValidationException(CommandError* errors, unsigned int count) 
	: mErrors(errors), mCount(count), IValidationException(mErrors, mCount)
{
}

ValidationException::~ValidationException()
{
	delete mErrors;
}


///////////////////////////////////////////////////////////////////

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

		throw ValidationException(errors, mErrors.size());
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

///////////////////////////////////////////////////////////////////

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

void GLFramework::RegisterErrorCallback(IErrorCallback* callback)
{
	if(callback != NULL)
		mErrorCallback = callback;
	else
		mErrorCallback = &mDefaultErrorCallback;
}

void GLFramework::glDeleteTextures(GLsizei n, const GLuint* textures)
{
	GLDeleteTextures* command = new GLDeleteTextures(n, textures);
	mCommands.push(command);
}

void GLFramework::glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
	GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	GLTexImage2D* command = new GLTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
	mCommands.push(command);
}

void GLFramework::glBindTexture(GLenum target, GLuint texture)
{
	GLBindTexture* command = new GLBindTexture(target, texture);
	mCommands.push(command);
}

IReturns<GLenum>* GLFramework::glGetError()
{
	GLGetError* command = new GLGetError();
	mCommands.push(command);
	return command;
}

void GLFramework::glGenTextures(GLsizei n, GLuint* textures)
{
	GLGenTextures* command = new GLGenTextures(n, textures);
	mCommands.push(command);
}

void GLFramework::glFlush()
{
	GLFlush* command = new GLFlush();
	mCommands.push(command);
}

void GLFramework::glBlendFunc(GLenum sfactor, GLenum dfactor)
{
	GLBlendFunc* command = new GLBlendFunc(sfactor, dfactor);
	mCommands.push(command);
}

void GLFramework::glUseProgram(GLuint program)
{
	GLUseProgram* command = new GLUseProgram(program);
	mCommands.push(command);
}

ICommand* GLFramework::TryGet()
{
	std::queue<ICommand*>& commands = __instance->mCommands;
	if(commands.empty())
		return NULL;

	ICommand* cmd = commands.front();
	commands.pop();
	return cmd;
}

void GLFramework::AddBadParameter(const ICommand* command, const char* paramName, std::string expected, std::string actual)
{
	__instance->mErrorCallback->OnBadParameter(command, paramName, expected.c_str(), actual.c_str());
}

void GLFramework::AddBadFunctionCalled(const ICommand* command, const char* expected)
{
	__instance->mErrorCallback->OnBadFunctionCalled(command, expected);
}

namespace glmock {
	std::string IntToString(GLint val) {
		std::stringstream ss;
		ss << val;
		return ss.str();
	}
	
	std::string FloatToString(GLfloat val) {
		std::stringstream ss;
		ss << val;
		return ss.str();
	}

	std::string DoubleToString(GLdouble val) {
		std::stringstream ss;
		ss << val;
		return ss.str();
	}
}