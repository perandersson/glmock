#include "glTexImage2D.h"
#include "../gl_framework.h"
#include <memory>
using namespace glmock;

GLTexImage2D::GLTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
	GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) 
	: GLCommand("glTexImage2D"),
	mTarget(target), mLevel(level), mInternalFormat(internalformat), mWidth(width),
	mHeight(height), mBorder(border), mFormat(format), mType(type), mPixels(pixels)
{
}

GLTexImage2D::~GLTexImage2D()
{
}

void GLTexImage2D::Eval(GLenum target, GLint level, GLint internalformat, GLsizei width, 
	GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	if(mTarget != target) {
		GLFramework::AddBadParameter(this->Name, "target", EnumToString(mTarget), EnumToString(target));
	}

	if(mLevel != level) {
		GLFramework::AddBadParameter(this->Name, "level", IntToString(mLevel), IntToString(level));
	}

	if(mInternalFormat != internalformat) {
		GLFramework::AddBadParameter(this->Name, "internalformat", IntToString(mInternalFormat), IntToString(internalformat));
	}
	
	if(mWidth != width) {
		GLFramework::AddBadParameter(this->Name, "width", IntToString(mWidth), IntToString(width));
	}
	
	if(mHeight != height) {
		GLFramework::AddBadParameter(this->Name, "height", IntToString(mHeight), IntToString(height));
	}
	
	if(mBorder != border) {
		GLFramework::AddBadParameter(this->Name, "border", IntToString(mBorder), IntToString(border));
	}

	if(mBorder != border) {
		GLFramework::AddBadParameter(this->Name, "border", IntToString(mBorder), IntToString(border));
	}
	
	if(mFormat != format) {
		GLFramework::AddBadParameter(this->Name, "format", EnumToString(mFormat), EnumToString(format));
	}
	
	if(mType != type) {
		GLFramework::AddBadParameter(this->Name, "type", EnumToString(mType), EnumToString(type));
	}
}

extern "C" {
	DLL_EXPORT void CALL_CONV glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, 
		GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
			GLTexImage2D* command = GLFramework::CastAndGet<GLTexImage2D>("glTexImage2D");
			if(command != NULL) {
				command->Eval(target, level, internalformat, width, height, border, format, type, pixels);
			}
	}
}
