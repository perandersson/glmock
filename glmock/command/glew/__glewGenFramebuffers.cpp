#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewGenFramebuffers)(GLsizei n, GLuint* framebuffers){
	}
}
