#include "glFlush.h"
#include "../gl_framework.h"
using namespace glmock;

GLFlush::GLFlush()
	: GLCommand("glFlush")
{
}

GLFlush::~GLFlush()
{
}

extern "C" {
	DLL_EXPORT void CALL_CONV glFlush(void) {
		GLFlush* command = GLFramework::CastAndGet<GLFlush>("glFlush");
		if(command != NULL) {
			delete command;
		}
	}
}
