#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef wglCreateContextAttribsARB
	HGLRC CALL_CONV wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int* attribList) {
		return NULL;
	}
	DLL_EXPORT PFNWGLCREATECONTEXTATTRIBSARBPROC __wglewCreateContextAttribsARB = &wglCreateContextAttribsARB;
}
