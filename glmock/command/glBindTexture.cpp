#include "../glmock.h"
using namespace glmock;

extern "C" {
	void GL_FUNCTION(glBindTexture)(GLenum target, GLuint texture){
	}
}
