#pragma once

#include "defines.h"

namespace glmock
{
	//
	// Base class for all the OpenGL commands
	class DLL_EXPORT ICommand
	{
	public:
		virtual ~ICommand() {}
	};
}
