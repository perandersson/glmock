#include "glBindTexture.h"
#include "../gl_framework.h"
#include "../glmock.h"
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
		char expected[10] = {0};
		char actual[10] = {0};
		itoa(mTarget, expected, 10);
		itoa(target, actual, 10);
		GLFramework::OnBadParameter(this, "target", expected, actual);
	}

	if(mTexture != texture) {
		char expected[10] = {0};
		char actual[10] = {0};
		itoa(mTexture, expected, 10);
		itoa(texture, actual, 10);
		GLFramework::OnBadParameter(this, "texture", expected, actual);
	}
}

extern "C" {
	DLL_EXPORT void CALL_CONV glBindTexture(GLenum target, GLuint texture) {
		GLBindTexture* command = GLFramework::Get().CastAndGet<GLBindTexture>();
		if(command != NULL) {
			command->Eval(target, texture);
			delete command;
		}
	}
}
