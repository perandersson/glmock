#pragma once

#include "command.h"
#include "defines.h"
#include "exception.h"

// Commands
#include "command/glDeleteTextures.h"
#include "command/glBindTexture.h"
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
		virtual void OnBadParameter(const ICommand* command, const char* name, const char* expected, const char* actual) = 0;

		//
		virtual void OnBadFunctionCalled(const ICommand* command, const char* actual) = 0;
	};

	class DLL_EXPORT IFramework
	{
	public:
		virtual ~IFramework() {}

	public:
		virtual void RegisterErrorCallback(IErrorCallback* calback) = 0;

	public:
		virtual GLDeleteTextures* glDeleteTextures(GLsizei n, const GLuint* textures) = 0;
		virtual GLBindTexture* glBindTexture(GLenum target, GLuint texture) = 0;
		virtual GLBlendFunc* glBlendFunc(GLenum sfactor, GLenum dfactor) = 0;
		virtual GLGetError* glGetError() = 0;
	};

	// 
	// Create a mock framework instance
	extern DLL_EXPORT IFramework* Create();

	//
	// Destroys and validates the mock framework
	extern DLL_EXPORT void Destroy(IFramework* framework);

}