#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glDeleteShader
	void CALL_CONV glDeleteShader(GLuint shader) {
	}
	DLL_EXPORT PFNGLDELETESHADERPROC __glewDeleteShader = &glDeleteShader; 
}
