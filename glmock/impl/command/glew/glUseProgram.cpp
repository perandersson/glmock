#include "glUseProgram.h"
#include "../../gl_framework.h"
using namespace glmock;

GLUseProgram::GLUseProgram(GLuint program)
	: GLCommand("glUseProgram"), mProgram(program)
{
}

GLUseProgram::~GLUseProgram()
{
}

void GLUseProgram::Eval(GLuint program)
{
	if(mProgram != program) {
		GLFramework::AddBadParameter(this->Name, "program", IntToString(mProgram), IntToString(program));
	}
}

extern "C" {
	#undef glUseProgram
	void CALL_CONV glUseProgram(GLuint program) {
		GLUseProgram* command = GLFramework::CastAndGet<GLUseProgram>("glUseProgram");
		if(command != NULL) {
			command->Eval(program);
			delete command;
		}
	}

	DLL_EXPORT PFNGLUSEPROGRAMPROC __glewUseProgram = &glUseProgram;
}

