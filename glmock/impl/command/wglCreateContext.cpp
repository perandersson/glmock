#include "../gl_framework.h"
using namespace glmock;

#ifdef WIN32

extern "C" {
#undef glBindBuffer
	DLL_EXPORT HGLRC CALL_CONV wglCreateContext(HDC hdc) {
		return NULL;
	}
}

#endif