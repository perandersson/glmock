#include "../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glUseProgram
	void CALL_CONV glUseProgram(GLuint program) {
	}

	DLL_EXPORT PFNGLUSEPROGRAMPROC __glewUseProgram = &glUseProgram;
}

