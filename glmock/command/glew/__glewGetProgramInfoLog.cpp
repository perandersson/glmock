#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLuint __glewGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {
		return 0;
	}
}
