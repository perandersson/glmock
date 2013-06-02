#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewDeleteFramebuffers)(GLsizei n, const GLuint* framebuffers){
	}
}
