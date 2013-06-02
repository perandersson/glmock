#pragma once

#include "command.h"
#include "defines.h"
#include "exception.h"

// Commands
#include "command/glDeleteTextures.h"
#include "command/glGetError.h"

namespace glmock
{
	class DLL_EXPORT IFramework
	{
	public:
		virtual ~IFramework() {}

	public:
		virtual GLDeleteTextures* glDeleteTextures(GLsizei n, const GLuint* textures) = 0;
		virtual GLGetError* glGetError() = 0;
	};

	// 
	// Create a mock framework instance
	extern DLL_EXPORT IFramework* Create();

	//
	// Destroys and validates the mock framework
	extern DLL_EXPORT void Destroy(IFramework* framework);

}