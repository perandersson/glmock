#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glDeleteVertexArrays
	void CALL_CONV glDeleteVertexArrays(GLsizei n, const GLuint* arrays) {
	}
	DLL_EXPORT PFNGLDELETEVERTEXARRAYSPROC __glewDeleteVertexArrays = &glDeleteVertexArrays;
}
