#pragma once

#include "../framework.h"
#include "../defines.h"
#include "gl_strings.h"
#include "gl_command.h"

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

	class GLFramework : public IFramework
	{
	private:
		static GLFramework& Get();
		
		//
		// @return The next command in the prediction queue; NULL if no commands are available.
		static GLCommand* TryGet();
		
	public:
		GLFramework(IErrorCallback* calback);
		~GLFramework();
		
		//
		// Add an error for when a bad parameter was supplied to a function
		static void AddBadParameter(const char* function, const char* paramName, std::string expected, std::string actual);

		//
		// Add an error if a bad/invalid function was called.
		static void AddBadFunctionCalled(const char* expected, const char* actual);
		
		//
		// Add an error if a bad/invalid function was called.
		static void AddUnspecifiedFunctionCalled(const char* expected);

	// IFramework
	public:
		virtual void glGetIntegerv(GLenum pname, GLint* params);
		virtual void glDeleteTextures(GLsizei n, const GLuint* textures);
		virtual void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
			GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
		virtual void glBindTexture(GLenum target, GLuint texture);
		virtual void glBlendFunc(GLenum sfactor, GLenum dfactor);
		virtual IReturns<GLenum>* glGetError();
		virtual void glGenTextures(GLsizei n, GLuint* textures);
		virtual void glFlush();

		virtual void glUseProgram(GLuint program);

	public:
		//
		// Retrieves the element at the top of the queue
		template<class T>
		static T* CastAndGet(const char* expected) {
			GLCommand* cmd = TryGet();
			if(cmd == 0) {
				AddUnspecifiedFunctionCalled(expected);
				return 0;
			}

			T* casted = dynamic_cast<T*>(cmd);
			if(casted == 0) {
				AddBadFunctionCalled(expected, cmd->Name);
				if(cmd != 0)
					delete cmd;
			}

			return casted;
		}
		

	private:
		std::queue<GLCommand*> mCommands;
		IErrorCallback* mErrorCallback;
	};

	extern std::string IntToString(GLint val);
	extern std::string FloatToString(GLfloat val);
	extern std::string DoubleToString(GLdouble val);
}
