#include "../glmock.h"
using namespace glmock;

extern "C" {
	void GL_FUNCTION(glTexParameteri)(GLenum target, GLenum pname, GLint param){
	}
}
