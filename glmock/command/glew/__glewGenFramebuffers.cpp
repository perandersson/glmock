#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GLEW_FUNCTION(__glewGenFramebuffers)(GLsizei n, GLuint* framebuffers){
	}
}
