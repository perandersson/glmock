#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glDeleteBuffers
	void CALL_CONV glDeleteBuffers(GLsizei n, const GLuint* buffers) {
	}
	DLL_EXPORT PFNGLDELETEBUFFERSPROC __glewDeleteBuffers = &glDeleteBuffers;
}
