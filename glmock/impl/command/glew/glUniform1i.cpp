#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glUniform1i
	void CALL_CONV glUniform1i(GLint location, GLint v0) {
	}
	DLL_EXPORT PFNGLUNIFORM1IPROC __glewUniform1i = &glUniform1i;
}
