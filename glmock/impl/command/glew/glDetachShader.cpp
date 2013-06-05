#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glDetachShader
	void CALL_CONV glDetachShader(GLuint program, GLuint shader) {
	}
	DLL_EXPORT PFNGLDETACHSHADERPROC __glewDetachShader = &glDetachShader;
}
