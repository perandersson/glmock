#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GLEW_FUNCTION(__glewUniform2fv)(GLint location, GLsizei count, const GLfloat* value){
	}
}
