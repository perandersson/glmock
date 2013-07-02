#pragma once

#include "../../framework.h"
#include "../gl_command.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glDeleteTextures.xml
	class GLGetError : public IReturns<GLenum>, public GLCommand
	{
	public:
		GLGetError();
		virtual ~GLGetError();

	public:
		virtual void Returns(GLenum returns);

	public:
		// 
		GLenum Eval();

	private:
		GLenum mReturns;
	};
}
