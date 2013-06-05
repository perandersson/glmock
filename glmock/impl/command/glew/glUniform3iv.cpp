#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glUniform3iv
	void CALL_CONV glUniform3iv(GLint location, GLsizei count, const GLint* value) {
	}
	DLL_EXPORT PFNGLUNIFORM3IVPROC __glewUniform3iv = &glUniform3iv;
}
