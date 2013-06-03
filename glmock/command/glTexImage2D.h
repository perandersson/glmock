#pragma once

#include "../command.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glTexImage2D.xml
	class DLL_EXPORT GLTexImage2D : public ICommand
	{
	public:
		GLTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
			GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
		virtual ~GLTexImage2D();

	public:
		// 
		void Eval(GLenum target, GLint level, GLint internalformat, GLsizei width, 
			GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);

	private:
		GLenum mTarget;
		GLint mLevel;
		GLint mInternalFormat;
		GLsizei mWidth; 
		GLsizei mHeight;
		GLint mBorder;
		GLenum mFormat;
		GLenum mType;
		const GLvoid* mPixels;
	};
}
