#include "../glmock.h"
using namespace glmock;

extern "C" {
	void GL_FUNCTION(glDrawArrays)(GLenum mode, GLint first, GLsizei count){
	}
}
