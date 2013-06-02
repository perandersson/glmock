#include "../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GL_FUNCTION(glBindTexture)(GLenum target, GLuint texture){
	}
}
