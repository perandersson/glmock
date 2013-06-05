#include "../gl_framework.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void CALL_CONV glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices) {
	}
}
