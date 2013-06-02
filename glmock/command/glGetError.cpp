#include "../glmock.h"
using namespace glmock;


extern "C" {
	GLenum GL_FUNCTION(glGetError)(){
		return GL_NO_ERROR;
	}
}
