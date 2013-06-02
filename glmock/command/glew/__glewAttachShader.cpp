#include "../../glmock.h"
using namespace glmock;

extern "C" {
	GLuint GLEW_FUNCTION(__glewAttachShader)(GLuint program, GLuint shader){
		return 0;
	}
}
