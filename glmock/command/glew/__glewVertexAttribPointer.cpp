#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void __glewVertexAttribPointer(GLuint index, GLint size, GLenum type, 
		GLboolean normalized, GLsizei stride, const GLvoid* pointer) {
	}
}
