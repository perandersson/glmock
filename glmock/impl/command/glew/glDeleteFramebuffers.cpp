#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glDeleteFramebuffers
	void CALL_CONV glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) {
	}
	DLL_EXPORT PFNGLDELETEFRAMEBUFFERSPROC __glewDeleteFramebuffers = &glDeleteFramebuffers;
}
