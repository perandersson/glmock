#include "../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void CALL_CONV glGenTextures(GLsizei n, const GLint* textures) {
	}
}
