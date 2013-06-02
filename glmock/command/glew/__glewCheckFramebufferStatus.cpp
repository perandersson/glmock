#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLenum __glewCheckFramebufferStatus(GLenum target) {
		return GL_FRAMEBUFFER_COMPLETE;
	}
}
