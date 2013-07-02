#include "glBlendFunc.h"
#include "../gl_framework.h"
using namespace glmock;

GLBlendFunc::GLBlendFunc(GLenum sfactor, GLenum dfactor)
	: GLCommand("glBlendFunc"), mSFactor(sfactor), mDFactor(dfactor)
{
}

GLBlendFunc::~GLBlendFunc()
{
}

void GLBlendFunc::Eval(GLenum sfactor, GLenum dfactor)
{
	if(sfactor != mSFactor) {
		const char* expected = AsString(mSFactor);
		const char* actual = AsString(sfactor);
		GLFramework::AddBadParameter(this->Name, "sfactor", expected, actual);
	}

	if(dfactor != mDFactor) {
		const char* expected = AsString(mDFactor);
		const char* actual = AsString(dfactor);
		GLFramework::AddBadParameter(this->Name, "dfactor", expected, actual);
	}
}

const char* GLBlendFunc::AsString(GLenum value)
{
	const char* str = 0;
	switch(value)
	{
	case GL_ZERO: str = AS_STRING(GL_ZERO); break;
	case GL_ONE: str = AS_STRING(GL_ONE); break;
	case GL_SRC_COLOR: str = AS_STRING(GL_SRC_COLOR); break;
	case GL_ONE_MINUS_SRC_COLOR: str = AS_STRING(GL_ONE_MINUS_SRC_COLOR); break;
	case GL_DST_COLOR: str = AS_STRING(GL_DST_COLOR); break;
	case GL_ONE_MINUS_DST_COLOR: str = AS_STRING(GL_ONE_MINUS_DST_COLOR); break;
	case GL_SRC_ALPHA: str = AS_STRING(GL_SRC_ALPHA); break;
	case GL_ONE_MINUS_SRC_ALPHA: str = AS_STRING(GL_ONE_MINUS_SRC_ALPHA); break;
	case GL_DST_ALPHA: str = AS_STRING(GL_DST_ALPHA); break;
	case GL_ONE_MINUS_DST_ALPHA: str = AS_STRING(GL_ONE_MINUS_DST_ALPHA); break;
	case GL_CONSTANT_COLOR: str = AS_STRING(GL_CONSTANT_COLOR); break;
	case GL_ONE_MINUS_CONSTANT_COLOR: str = AS_STRING(GL_ONE_MINUS_CONSTANT_COLOR); break;
	case GL_CONSTANT_ALPHA: str = AS_STRING(GL_CONSTANT_ALPHA); break;
	case GL_ONE_MINUS_CONSTANT_ALPHA: str = AS_STRING(GL_ONE_MINUS_CONSTANT_ALPHA); break;
	case GL_SRC_ALPHA_SATURATE: str = AS_STRING(GL_SRC_ALPHA_SATURATE); break;
	case GL_SRC1_COLOR: str = AS_STRING(GL_SRC1_COLOR); break;
	case GL_ONE_MINUS_SRC1_COLOR: str = AS_STRING(GL_ONE_MINUS_SRC1_COLOR); break;
	case GL_SRC1_ALPHA: str = AS_STRING(GL_SRC1_ALPHA); break;
	case GL_ONE_MINUS_SRC1_ALPHA: str = AS_STRING(GL_ONE_MINUS_SRC1_ALPHA); break;
	default: str = AS_STRING(UNKNOWN); str = AS_STRING(UNKNOWN); break;
	};
	return str;
}

extern "C" {
	DLL_EXPORT void CALL_CONV glBlendFunc(GLenum sfactor, GLenum dfactor) {
		GLBlendFunc* command = GLFramework::CastAndGet<GLBlendFunc>("glBlendFunc");
		if(command != NULL) {
			command->Eval(sfactor, dfactor);
		}
	}
}
