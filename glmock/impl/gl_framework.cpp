#include "gl_framework.h"
#include <sstream>
#include <map>
#include <string>

#include "command/glGetIntegerv.h"
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

GLFramework* __instance = 0;
GLFramework::GLFramework(IErrorCallback* calback)
	: mErrorCallback(calback)
{
	__instance = this;
}

GLFramework::~GLFramework()
{
	__instance = 0;
	if(mCommands.size() > 0) {
		// Not all commands where invoked!!!
		while(!mCommands.empty()) {
			GLCommand* cmd = mCommands.front();
			mErrorCallback->OnFunctionNotCalled(cmd->Name);
			mCommands.pop();
		}
	}

	delete mErrorCallback;
}

void GLFramework::glGetIntegerv(GLenum pname, GLint* params)
{
	GLGetIntegerv* command = new GLGetIntegerv(pname, params);
	mCommands.push(command);
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

GLCommand* GLFramework::TryGet()
{
	if(__instance == NULL) {
		throw new MockEngineNotInitializedException();
	}

	std::queue<GLCommand*>& commands = __instance->mCommands;
	if(commands.empty())
		return NULL;

	GLCommand* cmd = commands.front();
	commands.pop();
	return cmd;
}

void GLFramework::AddBadParameter(const char* function, const char* paramName, std::string expected, std::string actual)
{
	__instance->mErrorCallback->OnBadParameter(function, paramName, expected.c_str(), actual.c_str());
}

void GLFramework::AddBadFunctionCalled(const char* expected, const char* actual)
{
	__instance->mErrorCallback->OnBadFunctionCalled(expected, actual);
}

void GLFramework::AddUnspecifiedFunctionCalled(const char* expected)
{
	__instance->mErrorCallback->OnUnspecifiedFunctionCalled(expected);
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