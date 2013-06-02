#include "../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GL_FUNCTION(glViewport)(GLint x, GLint y, GLsizei width, GLsizei height){
	}
}
