#pragma once

#include "../../gl_command.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glUseProgram.xml
	class GLUseProgram : public GLCommand
	{
	public:
		GLUseProgram(GLuint program);
		virtual ~GLUseProgram();

	public:
		void Eval(GLuint program);
		
	private:
		GLenum mProgram;
	};
}
