#include "glBindTexture.h"
#include "../gl_framework.h"
using namespace glmock;

GLBindTexture::GLBindTexture(GLenum target, GLuint texture)
	: mTarget(target), mTexture(texture)
{
}

GLBindTexture::~GLBindTexture()
{
}

void GLBindTexture::Eval(GLenum target, GLuint texture)
{
	if(mTarget != target) {
		GLFramework::AddBadParameter(this, "target", EnumToString(GL_BIND_TEXTURE, mTarget), EnumToString(GL_BIND_TEXTURE, target));
	}

	if(mTexture != texture) {
		char expected[10] = {0};
		char actual[10] = {0};
		itoa(mTexture, expected, 10);
		itoa(texture, actual, 10);
		GLFramework::AddBadParameter(this, "texture", expected, actual);
	}
}

extern "C" {
	DLL_EXPORT void CALL_CONV glBindTexture(GLenum target, GLuint texture) {
		GLBindTexture* command = GLFramework::CastAndGet<GLBindTexture>();
		if(command != NULL) {
			command->Eval(target, texture);
			delete command;
		}
	}
}
