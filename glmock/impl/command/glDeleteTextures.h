#pragma once

#include "../gl_command.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glDeleteTextures.xml
	class GLDeleteTextures : public GLCommand
	{
	public:
		GLDeleteTextures(GLsizei n, const GLuint* textures);
		virtual ~GLDeleteTextures();

	public:
		// 
		void Eval(GLsizei n, const GLuint* textures);

	private:
		GLsizei mN;
		const GLuint* mTextures;
	};
}
