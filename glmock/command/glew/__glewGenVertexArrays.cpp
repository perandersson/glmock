#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewGenVertexArrays)(GLsizei n, GLuint* arrays){
	}
}
