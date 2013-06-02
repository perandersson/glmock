#pragma once

#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "command.h"
#include "defines.h"

// Commands
#include "command/glDeleteTextures.h"

namespace glmock
{
	class GLMockException
	{
	public:
		GLMockException(std::string& message);
		~GLMockException();

		//
		std::string GetMessage();

	private:
		std::string mMessage;
	};

	class GLMock
	{
	public:
		static GLMock& Get();

	public:
		GLMock();
		~GLMock();

		//
		//
		GLDeleteTextures* glDeleteTextures();

		//
		// Retrieves the element at the top of the queue
		template<class T>
		T* CastAndGet() {
			ICommand* cmd = mCommands.front();
			mCommands.pop();
			return dynamic_cast<T*>(cmd);
		}

		//
		// 
		void AddCommandError(const char* command, const char* error);
		
	private:
		std::queue<ICommand*> mCommands;
		std::vector<CommandError*> mErrors;
	};
}