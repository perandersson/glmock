#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewDeleteVertexArrays)(GLsizei n, const GLuint* arrays){
	}
}
