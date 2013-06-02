#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLuint __glewGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {
		return 0;
	}
}
