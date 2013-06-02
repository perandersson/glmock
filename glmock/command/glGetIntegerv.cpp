#include "../glmock.h"
using namespace glmock;

extern "C" {
	void GL_FUNCTION(glGetIntegerv)(GLenum pname, GLint *params){
	}
}
