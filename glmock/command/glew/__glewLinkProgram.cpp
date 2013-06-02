#include "../../glmock.h"
using namespace glmock;

extern "C" {
	GLuint GLEW_FUNCTION(__glewLinkProgram)(GLuint program){
		return 0;
	}
}
