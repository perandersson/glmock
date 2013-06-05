#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glCreateShader
	GLuint CALL_CONV glCreateShader(GLuint shader) {
		return 0;
	}
	PFNGLCREATESHADERPROC __glewCreateShader = &glCreateShader;
}
