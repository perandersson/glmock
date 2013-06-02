#pragma once

#include "defines.h"

namespace glmock
{
	//
	// Container for the multiple command errors occuring inside the mock framework
	struct DLL_EXPORT CommandError
	{
		char Command[50];
		char Error[128];
	};

	//
	// Base class for all the OpenGL commands
	class DLL_EXPORT ICommand
	{
	public:
		virtual ~ICommand() {}
	};
}
