#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewUniform3iv)(GLint location, GLsizei count, const GLint* value){
	}
}
