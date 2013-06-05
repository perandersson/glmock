#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
#undef glActiveTexture
	void CALL_CONV glActiveTexture(GLenum texture) {
	}
	DLL_EXPORT PFNGLACTIVETEXTUREPROC __glewActiveTexture = &glActiveTexture; 
}
