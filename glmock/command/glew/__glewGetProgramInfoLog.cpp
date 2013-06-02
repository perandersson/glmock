#include "../../glmock.h"
using namespace glmock;

extern "C" {
	GLuint GLEW_FUNCTION(__glewGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog){
		return 0;
	}
}
