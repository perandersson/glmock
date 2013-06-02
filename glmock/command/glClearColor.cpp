#include "../glmock.h"
using namespace glmock;

extern "C" {
	DLL_EXPORT void GL_FUNCTION(glClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha){
	}
}
