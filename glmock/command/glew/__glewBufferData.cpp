#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GLEW_FUNCTION(__glewBufferData)(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage){
	}
}
