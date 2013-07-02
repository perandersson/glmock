#include "glBindTexture.h"
#include "../gl_framework.h"
using namespace glmock;

GLBindTexture::GLBindTexture(GLenum target, GLuint texture)
	: GLCommand("glBindTexture"),
	mTarget(target), mTexture(texture)
{
}

GLBindTexture::~GLBindTexture()
{
}

void GLBindTexture::Eval(GLenum target, GLuint texture)
{
	if(mTarget != target) {
		GLFramework::AddBadParameter(this->Name, "target", EnumToString(mTarget), EnumToString(target));
	}

	if(mTexture != texture) {
		GLFramework::AddBadParameter(this->Name, "texture", IntToString(mTexture), IntToString(texture));
	}
}

extern "C" {
	DLL_EXPORT void CALL_CONV glBindTexture(GLenum target, GLuint texture) {
		GLBindTexture* command = GLFramework::CastAndGet<GLBindTexture>("glBindTexture");
		if(command != NULL) {
			command->Eval(target, texture);
			delete command;
		}
	}
}
