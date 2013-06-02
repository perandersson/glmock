#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLuint GLEW_FUNCTION(__glewCreateProgram)(){
		return 0;
	}
}
