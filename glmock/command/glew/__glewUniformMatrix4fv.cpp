#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	}
}
