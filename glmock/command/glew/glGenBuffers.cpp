#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewGenBuffers(GLsizei n, GLuint* buffers) {
	}
}
