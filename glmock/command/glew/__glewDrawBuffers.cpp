#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewDrawBuffers)(GLsizei n, const GLenum* bufs){
	}
}
