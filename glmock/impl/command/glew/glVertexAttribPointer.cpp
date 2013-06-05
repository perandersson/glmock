#include "../../../glmock.h"
using namespace glmock;

extern "C" {
	#undef glVertexAttribPointer
	void CALL_CONV glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) {
	}
	DLL_EXPORT PFNGLVERTEXATTRIBPOINTERPROC __glewVertexAttribPointer = &glVertexAttribPointer;
}
