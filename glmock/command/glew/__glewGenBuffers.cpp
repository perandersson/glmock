#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewGenBuffers)(GLsizei n, GLuint* buffers){
	}
}
