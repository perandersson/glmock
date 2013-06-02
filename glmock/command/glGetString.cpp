#include "../glmock.h"
using namespace glmock;

extern "C" {
	GLubyte strs[1] = {""};
	DLL_EXPORT const GLubyte * GL_FUNCTION(glGetString)(GLenum name) {
		return strs;
	}
}
