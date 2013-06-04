#pragma once

#include "../../command.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glUseProgram.xml
	class DLL_EXPORT GLUseProgram : public ICommand
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
