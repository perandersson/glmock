#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewDeleteBuffers(GLsizei n, const GLuint* buffers) {
	}
}
