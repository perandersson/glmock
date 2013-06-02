#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewBindFramebuffer(GLenum target, GLuint framebuffer) {
	}
}
