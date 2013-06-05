#include "../../gl_framework.h"
using namespace glmock;

extern "C" {
	#undef glGetShaderInfoLog
	void CALL_CONV glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {
	}
	DLL_EXPORT PFNGLGETSHADERINFOLOGPROC __glewGetShaderInfoLog = &glGetShaderInfoLog; 
}
