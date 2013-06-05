#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
#undef glBindBuffer
	void CALL_CONV glBindBuffer(GLenum target, GLuint buffer) {
	}
	DLL_EXPORT PFNGLBINDBUFFERPROC __glewBindBuffer = &glBindBuffer; 
}
