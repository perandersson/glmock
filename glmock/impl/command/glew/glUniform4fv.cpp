#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glUniform4fv
	void CALL_CONV glUniform4fv(GLint location, GLsizei count, const GLfloat* value) {
	}

	DLL_EXPORT PFNGLUNIFORM4FVPROC __glewUniform4fv = &glUniform4fv;
}
