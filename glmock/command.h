#pragma once

#include <string>
#include "defines.h"

namespace glmock
{
	struct CommandError
	{
		std::string Command;
		std::string Error;
	};

	//
	// Base class for all the OpenGL commands
	class ICommand
	{
	public:
		virtual ~ICommand() {}

	public:
	};
}
