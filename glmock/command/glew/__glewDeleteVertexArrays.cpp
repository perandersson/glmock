#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GLEW_FUNCTION(__glewDeleteVertexArrays)(GLsizei n, const GLuint* arrays){
	}
}
