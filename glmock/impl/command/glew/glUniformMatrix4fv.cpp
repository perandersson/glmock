#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glUniformMatrix4fv
	void CALL_CONV glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	}

	DLL_EXPORT PFNGLUNIFORMMATRIX4FVPROC __glewUniformMatrix4fv = &glUniformMatrix4fv;
}
