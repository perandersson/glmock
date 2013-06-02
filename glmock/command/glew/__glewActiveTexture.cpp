#include "../../glmock.h"
using namespace glmock;

extern "C" {
	void GLEW_FUNCTION(__glewActiveTexture)(GLenum texture){
	}
}
