#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
#undef glBindBuffer
	DLL_EXPORT GLboolean CALL_CONV wglewIsSupported(const char*) {
		return GL_TRUE;
	}
}
