#include "../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GL_FUNCTION(glTexParameteri)(GLenum target, GLenum pname, GLint param){
	}
}
