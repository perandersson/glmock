#include "glGetIntegerv.h"
#include "../gl_framework.h"
using namespace glmock;

GLGetIntegerv::GLGetIntegerv(GLenum pname, GLint *params)
	: GLCommand("glGetIntegerv"),
	mPname(pname), mParams(params)
{
}

GLGetIntegerv::~GLGetIntegerv()
{
}

void GLGetIntegerv::Eval(GLenum pname, GLint *params)
{
	if(mPname != pname) {
		GLFramework::AddBadParameter(this->Name, "pname", EnumToString(mPname), EnumToString(pname));
	}

	// Params = return value
	if(params == NULL) {
		GLFramework::AddBadParameter(this->Name, "params", "Not NULL", "NULL");
	} else {
		*params = *mParams;
	}
}

extern "C" {
	DLL_EXPORT void CALL_CONV glGetIntegerv(GLenum pname, GLint *params) {
		GLGetIntegerv* command = GLFramework::CastAndGet<GLGetIntegerv>("glGetIntegerv");
		if(command != NULL) {
			command->Eval(pname, params);
			delete command;
		}
	}
}
