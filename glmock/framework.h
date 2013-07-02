#pragma once

#include "command.h"
#include "exception.h"
#include "defines.h"

namespace glmock
{
	//
	// Template class which defines classes which returns some kind of data, such as glGetError which returns a GLenum value.
	template<typename T>
	class DLL_EXPORT IReturns
	{
	public:
		virtual ~IReturns() {}

	public:
		//
		// @param returns The value that the current function should return when being invoked.
		virtual void Returns(T returns) = 0;
	};

	//
	// Callback definition for when validation errors occure in the mock framework. 
	// @remark You are not allowed to throw any exception from within the methods exposed in this interface.
	class DLL_EXPORT IErrorCallback
	{
	public:
		virtual ~IErrorCallback() {}

	public:
		//
		// Method called when a validation error occures in the mock framework
		// @param expected
		virtual void OnFunctionNotCalled(const char* expected) = 0;

		//
		// Method called when a supplied parameter was invalid.
		// @param function
		// @param paramName The parameter name
		// @param expected The expected value
		// @param actual The actual value
		virtual void OnBadParameter(const char* function, const char* paramName, const char* expected, const char* actual) = 0;

		//
		// Method called when the wrong function was called, i.e. "glEnable" was the expected comand but you actually called "glGetError"
		// @param expected
		// @param actual The actual command
		virtual void OnBadFunctionCalled(const char* expected, const char* actual) = 0;

		//
		// Method called when a function is called that's we havn't registered. This happens if we call a OpenGL function
		// without actually registering that any calls are to be made.
		virtual void OnUnspecifiedFunctionCalled(const char* expected) = 0;
	};

	//
	// The OpenGL mock framework.
	class DLL_EXPORT IFramework
	{
	public:
		virtual ~IFramework() {}

	public:
		virtual void glGetIntegerv(GLenum pname, GLint* params) = 0;
		virtual void glDeleteTextures(GLsizei n, const GLuint* textures) = 0;
		virtual void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
			GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) = 0;
		virtual void glBindTexture(GLenum target, GLuint texture) = 0;
		virtual void glBlendFunc(GLenum sfactor, GLenum dfactor) = 0;
		virtual IReturns<GLenum>* glGetError() = 0;
		virtual void glGenTextures(GLsizei n, GLuint* textures) = 0;
		virtual void glFlush() = 0;

		virtual void glUseProgram(GLuint program) = 0;
	};

	// 
	// Create a mock framework instance. This instance is used to build up the neccessary command chain that we want to verify
	// @return A new framework instance.
	extern DLL_EXPORT IFramework* Create();
	
	// 
	// Create a mock framework instance. This instance is used to build up the neccessary command chain that we want to verify
	// @param callback The error callback listener. This instance will receive the errors raised in the mock framework. if {@code NULL} then
	//		the default error handler will be used.
	// @return A new framework instance.
	extern DLL_EXPORT IFramework* Create(IErrorCallback* callback);

	//
	// Destroys and validates the mock framework and validates the result (i.e. collects the errors and throws an exception).
	// @param framework
	// @throws glmock::IMockException If any validation errors occured during the execution time.
	// @remark This method will only throw the defined exception above if you use the default error handler. If you override the
	//	error listener then you are responsible for any errors that occured durin the execution time.
	extern DLL_EXPORT void Destroy(IFramework* framework);
}