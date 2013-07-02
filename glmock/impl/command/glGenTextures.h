#pragma once

#include "../gl_command.h"
#include "../gl_strings.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glGenTextures.xml
	class GLGenTextures : public GLCommand
	{
	public:
		GLGenTextures(GLsizei n, GLuint* textures);
		virtual ~GLGenTextures();

	public:
		void Eval(GLsizei n, GLuint* textures);

	private:
		GLsizei mN;
		GLuint* mTextures;
	};
}
