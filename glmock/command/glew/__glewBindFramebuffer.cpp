#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewBindFramebuffer)(GLenum target, GLuint framebuffer){
	}
}
