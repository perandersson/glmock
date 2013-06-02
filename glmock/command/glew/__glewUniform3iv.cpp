#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewUniform3iv(GLint location, GLsizei count, const GLint* value) {
	}
}
