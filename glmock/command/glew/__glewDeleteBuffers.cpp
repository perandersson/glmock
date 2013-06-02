#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GLEW_FUNCTION(__glewDeleteBuffers)(GLsizei n, const GLuint* buffers){
	}
}
