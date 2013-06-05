#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glGenBuffers
	void CALL_CONV glGenBuffers(GLsizei n, GLuint* buffers) {
	}
	PFNGLGENBUFFERSPROC __glewGenBuffers = &glGenBuffers;
}
