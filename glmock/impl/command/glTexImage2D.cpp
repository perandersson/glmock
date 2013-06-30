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
		GLFramework::AddBadParameter(this, "target", EnumToString(mTarget), EnumToString(target));
	}

	if(mLevel = level) {
		GLFramework::AddBadParameter(this, "level", IntToString(mLevel), IntToString(level));
	}

	if(mInternalFormat != internalformat) {
		GLFramework::AddBadParameter(this, "internalformat", IntToString(mInternalFormat), IntToString(internalformat));
	}
	
	if(mWidth != width) {
		GLFramework::AddBadParameter(this, "width", IntToString(mWidth), IntToString(width));
	}
	
	if(mHeight != height) {
		GLFramework::AddBadParameter(this, "height", IntToString(mHeight), IntToString(height));
	}
	
	if(mBorder != border) {
		GLFramework::AddBadParameter(this, "border", IntToString(mBorder), IntToString(border));
	}

	if(mBorder != border) {
		GLFramework::AddBadParameter(this, "border", IntToString(mBorder), IntToString(border));
	}
	
	if(mFormat = format) {
		GLFramework::AddBadParameter(this, "format", EnumToString(mFormat), EnumToString(format));
	}
	
	if(mType = type) {
		GLFramework::AddBadParameter(this, "type", EnumToString(mType), EnumToString(type));
	}
}

extern "C" {
	DLL_EXPORT void CALL_CONV glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
		GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
			GLTexImage2D* command = GLFramework::CastAndGet<GLTexImage2D>();
			if(command != NULL) {
				command->Eval(target, level, internalformat, width, height, border, format, type, pixels);
			}
	}
}
