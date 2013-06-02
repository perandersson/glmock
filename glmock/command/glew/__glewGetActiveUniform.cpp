#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewGetActiveUniform)(GLuint program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLchar* name){
	}
}
