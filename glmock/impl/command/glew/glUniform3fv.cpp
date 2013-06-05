#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glUniform3fv
	void CALL_CONV glUniform3fv(GLint location, GLsizei count, const GLfloat* value) {
	}
	DLL_EXPORT PFNGLUNIFORM3FVPROC __glewUniform3fv = &glUniform3fv;
}
