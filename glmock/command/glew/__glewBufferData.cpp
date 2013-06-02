#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewBufferData)(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage){
	}
}
