#include "../glmock.h"
using namespace glmock;

extern "C" {
	GLubyte strs[1] = {""};
	const GLubyte * GL_FUNCTION(glGetString)(GLenum name) {
		return strs;
	}
}
