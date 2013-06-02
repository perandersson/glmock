#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewGetProgramiv)(GLuint program, GLenum pname, GLint* param){
	}
}
