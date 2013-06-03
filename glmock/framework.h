#pragma once

#include "command.h"
#include "defines.h"
#include "exception.h"

// Commands
#include "command/glDeleteTextures.h"
#include "command/glBindTexture.h"
#include "command/glTexImage2D.h"
#include "command/glBlendFunc.h"
#include "command/glGetError.h"

namespace glmock
{
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
		virtual void RegisterErrorCallback(IErrorCallback* calback) = 0;

	public:
		virtual GLDeleteTextures* glDeleteTextures(GLsizei n, const GLuint* textures) = 0;
		virtual GLTexImage2D* glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
			GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) = 0;
		virtual GLBindTexture* glBindTexture(GLenum target, GLuint texture) = 0;
		virtual GLBlendFunc* glBlendFunc(GLenum sfactor, GLenum dfactor) = 0;
		virtual GLGetError* glGetError() = 0;
	};

	// 
	// Create a mock framework instance
	extern DLL_EXPORT IFramework* Create();

	//
	// Destroys and validates the mock framework and validates the result (i.e. collects the errors and throws an exception).
	// @param framework
	// @throws glmock::IMockException If any validation errors occured during the execution time.
	// @remark This method will only throw the defined exception above if you use the default error handler. If you override the
	//	error listener then you are responsible for any errors that occured durin the execution time.
	extern DLL_EXPORT void Destroy(IFramework* framework);

}