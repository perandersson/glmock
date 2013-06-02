#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewGetShaderiv)(GLuint shader, GLenum pname, GLint* param){
	}
}
