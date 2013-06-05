#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
#undef glCompileShader
	void CALL_CONV glCompileShader(GLuint shader) {
	}
	PFNGLCOMPILESHADERPROC __glewCompileShader = &glCompileShader; 
}
