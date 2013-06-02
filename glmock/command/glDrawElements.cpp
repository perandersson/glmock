#include "../glmock.h"
using namespace glmock;

extern "C" {
	void GL_FUNCTION(glDrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices){
	}
}
