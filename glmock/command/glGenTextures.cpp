#include "../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GL_FUNCTION(glGenTextures)(GLsizei n, const GLint* textures){
	}
}
