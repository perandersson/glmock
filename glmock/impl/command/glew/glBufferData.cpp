#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
#undef glBufferData
	void CALL_CONV glBufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage) {
	}
	DLL_EXPORT PFNGLBUFFERDATAPROC __glewBufferData = &glBufferData; 
}
