#include "../../glmock.h"
using namespace glmock;

extern "C" {
	GLuint GLEW_FUNCTION(__glewCreateShader)(GLuint shader){
		return 0;
	}
}
