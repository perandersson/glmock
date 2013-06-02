#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){
	}
}
