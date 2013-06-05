#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glGetShaderiv
	void CALL_CONV glGetShaderiv(GLuint shader, GLenum pname, GLint* param) {
	}
	DLL_EXPORT PFNGLGETSHADERIVPROC __glewGetShaderiv = &glGetShaderiv;
}
