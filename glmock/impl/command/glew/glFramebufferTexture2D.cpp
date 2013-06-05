#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glFramebufferTexture2D
	void CALL_CONV glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	}
	DLL_EXPORT PFNGLFRAMEBUFFERTEXTURE2DPROC __glewFramebufferTexture2D = &glFramebufferTexture2D; 
}
