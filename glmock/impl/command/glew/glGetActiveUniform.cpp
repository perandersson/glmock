#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glGetActiveUniform
	void CALL_CONV glGetActiveUniform(GLuint program, GLuint index, GLsizei maxLength, 
		GLsizei* length, GLint* size, GLenum* type, GLchar* name) {
	}
	DLL_EXPORT PFNGLGETACTIVEUNIFORMPROC __glewGetActiveUniform = &glGetActiveUniform; 
}
