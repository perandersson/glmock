#include "glUseProgram.h"
#include "../../glmock.h"
#include "../../gl_framework.h"
using namespace glmock;

GLUseProgram::GLUseProgram(GLuint program)
	: mProgram(program)
{
}

GLUseProgram::~GLUseProgram()
{
}

void GLUseProgram::Eval(GLuint program)
{
	if(mProgram != program) {
		char expected[10] = {0};
		char actual[10] = {0};
		itoa(mProgram, expected, 10);
		itoa(program, actual, 10);
		GLFramework::OnBadParameter(this, "program", expected, actual);
	}
}

extern "C" {
	#undef glUseProgram
	void CALL_CONV glUseProgram(GLuint program) {
		GLUseProgram* command = GLFramework::Get().CastAndGet<GLUseProgram>();
		if(command != NULL) {
			command->Eval(program);
			delete command;
		}
	}

	DLL_EXPORT PFNGLUSEPROGRAMPROC __glewUseProgram = &glUseProgram;
}

