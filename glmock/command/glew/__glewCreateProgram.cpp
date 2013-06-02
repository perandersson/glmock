#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLuint __glewCreateProgram(void) {
		return 0;
	}
}
