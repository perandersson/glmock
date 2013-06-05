#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glGenFramebuffers
	void CALL_CONV glGenFramebuffers(GLsizei n, GLuint* framebuffers) {
	}
	DLL_EXPORT PFNGLGENFRAMEBUFFERSPROC __glewGenFramebuffers = &glGenFramebuffers; 
}
