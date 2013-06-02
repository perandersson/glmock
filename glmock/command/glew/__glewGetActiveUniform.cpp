#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewGetActiveUniform(GLuint program, GLuint index, GLsizei maxLength, 
		GLsizei* length, GLint* size, GLenum* type, GLchar* name) {
	}
}
