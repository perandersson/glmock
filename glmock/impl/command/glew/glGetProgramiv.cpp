#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glGetProgramiv
	void CALL_CONV glGetProgramiv(GLuint program, GLenum pname, GLint* param) {
	}
	DLL_EXPORT PFNGLGETPROGRAMIVPROC __glewGetProgramiv = &glGetProgramiv;
}
