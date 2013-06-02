#include "glGetError.h"
#include "../gl_framework.h"
using namespace glmock;

GLGetError::GLGetError() : mReturns(GL_NO_ERROR)
{
}

GLGetError::~GLGetError()
{
}

void GLGetError::Returns(GLenum returns)
{
	mReturns = returns;
}

GLenum GLGetError::Eval()
{
	return mReturns;
}

extern "C" {
	DLL_EXPORT GLenum CALL_CONV glGetError(void) {
		GLGetError* command = GLFramework::Get().CastAndGet<GLGetError>();
		if(command != NULL) {
			return command->Eval();
		}
		return GL_NO_ERROR;
	}
}
