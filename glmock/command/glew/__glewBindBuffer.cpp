#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GLEW_FUNCTION(__glewBindBuffer)(GLenum target, GLuint buffer){
	}
}
