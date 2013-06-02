#pragma once

#include "../command.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glDeleteTextures.xml
	class DLL_EXPORT GLGetError : public ICommand
	{
	public:
		GLGetError();
		virtual ~GLGetError();

	public:
		void Returns(GLenum returns);

	public:
		// 
		GLenum Eval();

	private:
		GLenum mReturns;
	};
}
