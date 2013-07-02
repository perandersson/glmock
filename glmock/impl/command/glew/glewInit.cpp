#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glGenBuffers
	DLL_EXPORT GLenum CALL_CONV glewInit() {
		return GLEW_OK;
	}
}
