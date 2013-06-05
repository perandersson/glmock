#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glGetProgramInfoLog
	void CALL_CONV glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {
	}
	PFNGLGETPROGRAMINFOLOGPROC __glewGetProgramInfoLog = &glGetProgramInfoLog;
}
