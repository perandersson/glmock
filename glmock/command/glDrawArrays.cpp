#include "../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GL_FUNCTION(glDrawArrays)(GLenum mode, GLint first, GLsizei count){
	}
}
