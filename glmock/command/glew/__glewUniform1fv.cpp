#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewUniform1fv(GLint location, GLsizei count, const GLfloat* value) {
	}
}
