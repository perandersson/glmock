#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLint __glewGetUniformLocation(GLuint program, const GLchar* name) {
		return 0;
	}
}
