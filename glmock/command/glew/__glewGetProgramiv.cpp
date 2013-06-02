#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewGetProgramiv(GLuint program, GLenum pname, GLint* param) {
	}
}
