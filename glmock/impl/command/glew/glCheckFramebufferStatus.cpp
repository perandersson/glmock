#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
#undef glCheckFramebufferStatus
	GLenum CALL_CONV glCheckFramebufferStatus(GLenum target) {
		return GL_FRAMEBUFFER_COMPLETE;
	}
	PFNGLCHECKFRAMEBUFFERSTATUSPROC __glewCheckFramebufferStatus = &glCheckFramebufferStatus; 
}
