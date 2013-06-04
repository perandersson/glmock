#pragma once

#include "framework.h"
#include "defines.h"
#include "gl_strings.h"

#include <string>
#include <queue>
#include <vector>

namespace glmock
{
	class ExceptionErrorCallback : public IErrorCallback
	{
	public:
		ExceptionErrorCallback();
		~ExceptionErrorCallback();

	public:
		virtual void OnCommandNotCalled(const ICommand* command);
		virtual void OnBadParameter(const ICommand* command, const char* name, const char* expected, const char* actual);
		virtual void OnBadFunctionCalled(const ICommand* command, const char* actual);

	private:
		std::vector<CommandError> mErrors;
	};

	class GLFramework : public IFramework
	{
	public:
		static GLFramework& Get();

	public:
		GLFramework();
		~GLFramework();

	// IFramework
	public:
		virtual void RegisterErrorCallback(IErrorCallback* calback);

		virtual GLDeleteTextures* glDeleteTextures(GLsizei n, const GLuint* textures);
		virtual GLTexImage2D* glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
			GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
		virtual GLBindTexture* glBindTexture(GLenum target, GLuint texture);
		virtual GLBlendFunc* glBlendFunc(GLenum sfactor, GLenum dfactor);
		virtual GLGetError* glGetError();
		virtual GLUseProgram* glUseProgram(GLuint program);

	public:
		//
		// Retrieves the element at the top of the queue
		template<class T>
		T* CastAndGet() {
			ICommand* cmd = mCommands.front();
			mCommands.pop();
			
			T* casted = dynamic_cast<T*>(cmd);
			if(casted == 0) {
				mErrorCallback->OnBadFunctionCalled(cmd, typeid(T).name());
				delete cmd;
			}

			return casted;
		}
		
		//
		static void OnBadParameter(const ICommand* command, const char* paramName, const char* expected, const char* actual);

	private:
		std::queue<ICommand*> mCommands;
		IErrorCallback* mErrorCallback;
		ExceptionErrorCallback mDefaultErrorCallback;
	};
}
