#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
#undef glAttachShader
	void CALL_CONV glAttachShader(GLuint program, GLuint shader) {
	}
	DLL_EXPORT PFNGLATTACHSHADERPROC __glewAttachShader = &glAttachShader; 
}
