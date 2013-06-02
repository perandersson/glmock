#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewUniform3fv)(GLint location, GLsizei count, const GLfloat* value){
	}
}
