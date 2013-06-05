#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glDrawBuffers
	void CALL_CONV glDrawBuffers(GLsizei n, const GLenum* bufs) {
	}
	DLL_EXPORT PFNGLDRAWBUFFERSPROC __glewDrawBuffers = &glDrawBuffers;
}
