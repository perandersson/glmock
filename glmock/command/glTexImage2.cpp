#include "../glmock.h"
using namespace glmock;

extern "C" {
	void GL_FUNCTION(glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels){
	}
}
