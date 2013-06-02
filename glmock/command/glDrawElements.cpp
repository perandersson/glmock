#include "../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GL_FUNCTION(glDrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices){
	}
}
