#pragma once

#include "../command.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glDeleteTextures.xml
	class GLDeleteTextures : public ICommand
	{
	public:
		GLDeleteTextures();
		virtual ~GLDeleteTextures();

		virtual const char* GetName() { return "glDeleteTextures"; }

	public:
		GLDeleteTextures* Expect(GLsizei n);
		void Result(const GLuint* textures);

	public:
		// 
		void Eval(GLsizei n, const GLuint* textures);

	private:
		GLsizei mExpect;
		const GLuint* mResult;
	};
}
