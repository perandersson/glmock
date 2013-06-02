#include "../../glmock.h"
using namespace glmock;

extern "C" {
	GLuint GLEW_FUNCTION(__glewGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog){
		return 0;
	}
}
