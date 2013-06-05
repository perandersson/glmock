#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glShaderSource
	void CALL_CONV glShaderSource(GLuint shader, GLsizei count, const GLchar** strings, const GLint* lengths) {	
	}
	DLL_EXPORT PFNGLSHADERSOURCEPROC __glewShaderSource = &glShaderSource;
}
