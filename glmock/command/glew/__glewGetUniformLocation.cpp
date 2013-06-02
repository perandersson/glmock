#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLint GLEW_FUNCTION(__glewGetUniformLocation)(GLuint program, const GLchar* name){
		return 0;
	}
}
