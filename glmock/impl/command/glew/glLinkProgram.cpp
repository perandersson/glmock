#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glLinkProgram
	void CALL_CONV glLinkProgram(GLuint program) {
	}
	DLL_EXPORT PFNGLLINKPROGRAMPROC __glewLinkProgram = &glLinkProgram;
}
