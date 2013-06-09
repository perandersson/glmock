#pragma once

#include "../framework.h"
#include "../defines.h"
#include "gl_strings.h"

#include <string>
#include <queue>
#include <vector>

namespace glmock
{
	//
	// Implementation of the validation exception - used by the default behaviour for when errors occure in the
	// mock framework.
	class ValidationException : public IValidationException
	{
	public:
		ValidationException(CommandError* errors, unsigned int count);
		~ValidationException();

	private:
		CommandError* mErrors;
		unsigned int mCount;
	};

	//
	// The default error callback listener. This will cause the exception {@code glmock::IMockException} to be thrown
	// with the complete information regarding all the errors if any error where raised.
	class ExceptionErrorCallback : public IErrorCallback
	{
	public:
		ExceptionErrorCallback();
		virtual ~ExceptionErrorCallback();

	public:
		virtual void OnCommandNotCalled(const ICommand* command);
		virtual void OnBadParameter(const ICommand* command, const char* name, const char* expected, const char* actual);
		virtual void OnBadFunctionCalled(const ICommand* command, const char* actual);

	private:
		std::vector<CommandError> mErrors;
	};

	class GLFramework : public IFramework
	{
	private:
		static GLFramework& Get();
		
		//
		// @return The next command in the prediction queue; NULL if no commands are available.
		static ICommand* TryGet();
		
	public:
		GLFramework();
		~GLFramework();
		
		//
		// Add an error for when a bad parameter was supplied to a function
		static void AddBadParameter(const ICommand* command, const char* paramName, const char* expected, const char* actual);

		//
		// Add an error if a bad/invalid function was called.
		static void AddBadFunctionCalled(const ICommand* command, const char* expected);

	// IFramework
	public:
		virtual void RegisterErrorCallback(IErrorCallback* calback);

		virtual void glDeleteTextures(GLsizei n, const GLuint* textures);
		virtual void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
			GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
		virtual void glBindTexture(GLenum target, GLuint texture);
		virtual void glBlendFunc(GLenum sfactor, GLenum dfactor);
		virtual IReturns<GLenum>* glGetError();
		virtual void glUseProgram(GLuint program);

	public:
		//
		// Retrieves the element at the top of the queue
		template<class T>
		static T* CastAndGet() {
			ICommand* cmd = TryGet();
			T* casted = dynamic_cast<T*>(cmd);
			if(casted == 0) {
				AddBadFunctionCalled(cmd, typeid(T).name());
				if(cmd != 0)
					delete cmd;
			}

			return casted;
		}
		

	private:
		std::queue<ICommand*> mCommands;
		IErrorCallback* mErrorCallback;
		ExceptionErrorCallback mDefaultErrorCallback;
	};

	extern std::string IntToString(GLint val);
	extern std::string FloatToString(GLfloat val);
	extern std::string DoubleToString(GLdouble val);
}
