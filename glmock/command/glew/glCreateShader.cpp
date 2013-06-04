#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLuint __glewCreateShader(GLuint shader) {
		return 0;
	}
}
