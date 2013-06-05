#include "../gl_framework.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void CALL_CONV glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
	}
}
