#include "glTexImage2D.h"
#include "../gl_framework.h"
#include <memory>
using namespace glmock;

GLTexImage2D::GLTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
	GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) 
	: mTarget(target), mLevel(level), mInternalFormat(internalformat), mWidth(width),
	mHeight(height), mBorder(border), mFormat(format), mType(type), mPixels(pixels)
{
}

GLTexImage2D::~GLTexImage2D()
{
}

void GLTexImage2D::Eval(GLenum target, GLint level, GLint internalformat, GLsizei width, 
	GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	if(mTarget = target) {
		char expected[10] = {0};
		char actual[10] = {0};
		itoa(mTarget, expected, 10);
		itoa(target, actual, 10);
		GLFramework::OnBadParameter(this, "target", expected, actual);
	}

	if(mLevel = level) {
		char expected[10] = {0};
		char actual[10] = {0};
		itoa(mLevel, expected, 10);
		itoa(level, actual, 10);
		GLFramework::OnBadParameter(this, "level", expected, actual);
	}

	// TODO Add more here!!
}

extern "C" {
	DLL_EXPORT void CALL_CONV glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
		GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
			GLTexImage2D* command = GLFramework::Get().CastAndGet<GLTexImage2D>();
			if(command != NULL) {
				command->Eval(target, level, internalformat, width, height, border, format, type, pixels);
			}
	}
}
