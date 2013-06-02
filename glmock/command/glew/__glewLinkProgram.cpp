#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLuint __glewLinkProgram(GLuint program) {
		return 0;
	}
}
