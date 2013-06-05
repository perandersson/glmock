#include "../gl_framework.h"
using namespace glmock;

extern "C" {
	GLubyte strs[1] = {""};
	DLL_EXPORT const GLubyte* CALL_CONV glGetString(GLenum name) {
		return strs;
	}
}
