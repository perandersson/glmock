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
		GLFramework::Get().AddCommandError(this, "Parameter 'target' is invalid");
	}

	if(mTexture != texture) {
		GLFramework::Get().AddCommandError(this, "Parameter 'texture' is invalid");
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
