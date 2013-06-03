#include "glBlendFunc.h"
#include "../gl_framework.h"
#include "../glmock.h"
using namespace glmock;

GLBlendFunc::GLBlendFunc(GLenum sfactor, GLenum dfactor)
	: mSFactor(sfactor), mDFactor(dfactor)
{
}

GLBlendFunc::~GLBlendFunc()
{
}

void GLBlendFunc::Eval(GLenum sfactor, GLenum dfactor)
{
	if(sfactor != mSFactor) {
		char expected[10] = {0};
		char actual[10] = {0};
		itoa(mSFactor, expected, 10);
		itoa(sfactor, actual, 10);
		GLFramework::OnBadParameter(this, "sfactor", expected, actual);
	}

	if(dfactor != mDFactor) {
		char expected[10] = {0};
		char actual[10] = {0};
		itoa(mDFactor, expected, 10);
		itoa(dfactor, actual, 10);
		GLFramework::OnBadParameter(this, "dfactor", expected, actual);
	}
}

extern "C" {
	DLL_EXPORT void CALL_CONV glBlendFunc(GLenum sfactor, GLenum dfactor) {
		GLBlendFunc* command = GLFramework::Get().CastAndGet<GLBlendFunc>();
		if(command != NULL) {
			command->Eval(sfactor, dfactor);
		}
	}
}
