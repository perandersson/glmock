#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glGenVertexArrays
	void CALL_CONV glGenVertexArrays(GLsizei n, GLuint* arrays) {
	}
	DLL_EXPORT PFNGLGENVERTEXARRAYSPROC __glewGenVertexArrays = &glGenVertexArrays; 
}
