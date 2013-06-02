#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewBindBuffer)(GLenum target, GLuint buffer){
	}
}
