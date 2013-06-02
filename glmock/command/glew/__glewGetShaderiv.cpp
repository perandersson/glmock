#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewGetShaderiv(GLuint shader, GLenum pname, GLint* param) {
	}
}
