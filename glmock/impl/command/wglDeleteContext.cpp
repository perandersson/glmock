#include "../gl_framework.h"
using namespace glmock;

#ifdef WIN32

extern "C" {
#undef glBindBuffer
	DLL_EXPORT BOOL CALL_CONV wglDeleteContext(HGLRC rc) {
		return TRUE;
	}
}

#endif