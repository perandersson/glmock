#include "../../glmock.h"
using namespace glmock;

extern "C" {
	GLuint GLEW_FUNCTION(__glewCreateProgram)(){
		return 0;
	}
}
