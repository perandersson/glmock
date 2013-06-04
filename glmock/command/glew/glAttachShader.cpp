#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLuint __glewAttachShader(GLuint program, GLuint shader) {
		return 0;
	}
}
