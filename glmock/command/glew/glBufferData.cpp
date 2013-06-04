#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewBufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage) {
	}
}
