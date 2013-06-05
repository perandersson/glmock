#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glEnableVertexAttribArray
	void CALL_CONV glEnableVertexAttribArray(GLuint en) {
	}
	PFNGLENABLEVERTEXATTRIBARRAYPROC __glewEnableVertexAttribArray = &glEnableVertexAttribArray; 
}
