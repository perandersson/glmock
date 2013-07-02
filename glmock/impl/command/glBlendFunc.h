#pragma once 

#include "../gl_command.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glBlendFunc.xml
	class GLBlendFunc : public GLCommand
	{
	public:
		GLBlendFunc(GLenum sfactor, GLenum dfactor);
		virtual ~GLBlendFunc();

	public:
		void Eval(GLenum sfactor, GLenum dfactor);
		
	private:
		const char* AsString(GLenum value);

	private:
		GLenum mSFactor;
		GLenum mDFactor;
	};
}
