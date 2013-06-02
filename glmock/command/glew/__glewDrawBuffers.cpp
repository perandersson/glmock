#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewDrawBuffers(GLsizei n, const GLenum* bufs) {
	}
}
