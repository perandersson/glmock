#include "../gl_framework.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void CALL_CONV glGetIntegerv(GLenum pname, GLint *params) {
	}
}