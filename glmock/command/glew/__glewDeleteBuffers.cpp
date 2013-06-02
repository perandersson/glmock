#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewDeleteBuffers)(GLsizei n, const GLuint* buffers){
	}
}
