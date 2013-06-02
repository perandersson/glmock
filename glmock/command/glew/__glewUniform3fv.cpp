#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewUniform3fv(GLint location, GLsizei count, const GLfloat* value) {
	}
}
