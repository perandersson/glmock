#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glUniform1fv
	void CALL_CONV glUniform1fv(GLint location, GLsizei count, const GLfloat* value) {
	}
	DLL_EXPORT PFNGLUNIFORM1FVPROC __glewUniform1fv = &glUniform1fv; 
}
