#pragma once

#include "../../command.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glDeleteTextures.xml
	class DLL_EXPORT GLDeleteTextures : public ICommand
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
