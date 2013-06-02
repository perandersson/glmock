#include "../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void CALL_CONV glBindTexture(GLenum target, GLuint texture) {
	}
}
