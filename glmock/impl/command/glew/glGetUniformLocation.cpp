#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glGetUniformLocation
	GLint CALL_CONV glGetUniformLocation(GLuint program, const GLchar* name) {
		return 0;
	}
	DLL_EXPORT PFNGLGETUNIFORMLOCATIONPROC __glewGetUniformLocation = &glGetUniformLocation;
}
