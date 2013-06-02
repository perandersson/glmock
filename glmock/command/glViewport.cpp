#include "../glmock.h"
using namespace glmock;

extern "C" {
	void GL_FUNCTION(glViewport)(GLint x, GLint y, GLsizei width, GLsizei height){
	}
}
