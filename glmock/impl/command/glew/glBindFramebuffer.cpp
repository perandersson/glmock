#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glBindFramebuffer
	void CALL_CONV glBindFramebuffer(GLenum target, GLuint framebuffer) {
	}
	PFNGLBINDFRAMEBUFFERPROC __glewBindFramebuffer = &glBindFramebuffer; 
}
