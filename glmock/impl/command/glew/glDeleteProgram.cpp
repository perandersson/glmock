#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glDeleteProgram
	void CALL_CONV glDeleteProgram(GLuint program) {
	}
	DLL_EXPORT PFNGLDELETEPROGRAMPROC __glewDeleteProgram = &glDeleteProgram; 
}
