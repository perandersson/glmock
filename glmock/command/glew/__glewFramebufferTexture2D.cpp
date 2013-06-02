#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GLEW_FUNCTION(__glewFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level){
	}
}
