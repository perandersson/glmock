#pragma once

#include "command.h"
#include "exception.h"
#include "defines.h"

namespace glmock
{
	//
	// Template class which defines classes which returns some kind of data, such as glGetError which returns a GLenum value.
	template<typename T>
	class DLL_EXPORT IReturns : public ICommand
	{
	public:
		//
		// @param returns The value that the current function should return when being invoked.
		virtual void Returns(T returns) = 0;
	};

	//
	// Callback definition for when validation errors occure in the mock framework
	class DLL_EXPORT IErrorCallback
	{
	public:
		virtual ~IErrorCallback() {}

	public:
		//
		// Method called when a validation error occures in the mock framework
		virtual void OnCommandNotCalled(const ICommand* command) = 0;

		//
		// Method called when a supplied parameter was invalid.
		// @param command
		// @param paramName The parameter name
		// @param expected The expected value
		// @param actual The actual value
		virtual void OnBadParameter(const ICommand* command, const char* paramName, const char* expected, const char* actual) = 0;

		//
		// Method called when the wrong function was called, i.e. "glEnable" was the expected comand but you actually called "glGetError"
		// @param command
		// @param actual The actual command
		virtual void OnBadFunctionCalled(const ICommand* command, const char* actual) = 0;
	};

	//
	// The OpenGL mock framework.
	class DLL_EXPORT IFramework
	{
	public:
		virtual ~IFramework() {}

	public:
		//
		// Register a custom error callback listener. This overrides the default behaviour which throws an exception 
		// if any error has occured during the execution time.
		//
		// @param callback The error callback listener. This instance will receive the errors raised in the mock framework. if {@code NULL} then
		//		the default error handler will be used.
		virtual void RegisterErrorCallback(IErrorCallback* callback) = 0;

	public:
		// OpenGL 1.0

		// OpenGL 2.0

		// OpenGL 3.0

		// OpenGL 3.3

		virtual void glDeleteTextures(GLsizei n, const GLuint* textures) = 0;
		virtual void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
			GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) = 0;
		virtual void glBindTexture(GLenum target, GLuint texture) = 0;
		virtual void glBlendFunc(GLenum sfactor, GLenum dfactor) = 0;
		virtual IReturns<GLenum>* glGetError() = 0;
		virtual void glUseProgram(GLuint program) = 0;
	};

	// 
	// Create a mock framework instance. This instance is used to build up the neccessary command chain that we want to verify
	// @return A new framework instance.
	extern DLL_EXPORT IFramework* Create();

	//
	// Destroys and validates the mock framework and validates the result (i.e. collects the errors and throws an exception).
	// @param framework
	// @throws glmock::IMockException If any validation errors occured during the execution time.
	// @remark This method will only throw the defined exception above if you use the default error handler. If you override the
	//	error listener then you are responsible for any errors that occured durin the execution time.
	extern DLL_EXPORT void Destroy(IFramework* framework);

}