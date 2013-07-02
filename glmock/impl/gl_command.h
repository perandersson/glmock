#pragma once
#include "../command.h"

namespace glmock
{
	class GLCommand : public ICommand
	{
	public:
		GLCommand(const char* name);
		~GLCommand();

	public:
		const char* Name;

	private:
		char mName[50];
	};
}
