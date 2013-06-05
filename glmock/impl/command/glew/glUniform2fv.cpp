#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glUniform2fv
	void CALL_CONV glUniform2fv(GLint location, GLsizei count, const GLfloat* value) {
	}
	DLL_EXPORT PFNGLUNIFORM2FVPROC __glewUniform2fv = &glUniform2fv;
}
