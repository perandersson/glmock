#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GLEW_FUNCTION(__glewUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	}
}
