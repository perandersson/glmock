#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
#undef glBindVertexArray
	void CALL_CONV glBindVertexArray(GLuint array) {
	}
	DLL_EXPORT PFNGLBINDVERTEXARRAYPROC __glewBindVertexArray = &glBindVertexArray; 
}
