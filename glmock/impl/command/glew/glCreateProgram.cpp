#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
#undef glCreateProgram
	GLuint CALL_CONV glCreateProgram(void) {
		return 0;
	}
	PFNGLCREATEPROGRAMPROC __glewCreateProgram = &glCreateProgram; 
}
