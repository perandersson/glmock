#include "../../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT GLuint GLEW_FUNCTION(__glewCreateShader)(GLuint shader){
		return 0;
	}
}
