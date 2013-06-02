#pragma once

#include "framework.h"

#include <string>
#include <queue>
#include <vector>

namespace glmock
{
	class GLFramework : public IFramework
	{
	public:
		static GLFramework& Get();

	public:
		GLFramework();
		~GLFramework();

	// IFramework
	public:
		virtual GLDeleteTextures* glDeleteTextures(GLsizei n, const GLuint* textures);
		virtual GLGetError* glGetError();

	public:
		//
		// Retrieves the element at the top of the queue
		template<class T>
		T* CastAndGet() {
			ICommand* cmd = mCommands.front();
			mCommands.pop();
			
			T* casted = dynamic_cast<T*>(cmd);
			if(casted == 0) {
				std::string error = "Expected: ";
				error += typeid(T).name();
				error += " but was: ";
				error += typeid(*cmd).name();
				AddCommandError(cmd, error.c_str());
				delete cmd;
			}

			return casted;
		}

		//
		// 
		void AddCommandError(ICommand* command, const char* error);
		
	private:
		std::queue<ICommand*> mCommands;
		std::vector<CommandError> mErrors;
	};

}
