#pragma once

#include "../command.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glBindTexture.xml
	class DLL_EXPORT GLBindTexture : public ICommand
	{
	public:
		GLBindTexture(GLenum target, GLuint texture);
		virtual ~GLBindTexture();

	public:
		void Eval(GLenum target, GLuint texture);

	private:
		const char* AsString(GLenum value);

	private:
		GLenum mTarget;
		GLuint mTexture;
	};
}
