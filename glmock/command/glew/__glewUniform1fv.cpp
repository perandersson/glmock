#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewUniform1fv)(GLint location, GLsizei count, const GLfloat* value){
	}
}
