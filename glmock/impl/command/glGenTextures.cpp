#include "glGenTextures.h"
#include "../gl_framework.h"
using namespace glmock;

GLGenTextures::GLGenTextures(GLsizei n, GLuint* textures)
	: GLCommand("glGenTextures"), mN(n), mTextures(textures)
{
}

GLGenTextures::~GLGenTextures()
{
}

void GLGenTextures::Eval(GLsizei n, GLuint* textures)
{
	if(mN != n) {
		GLFramework::AddBadParameter(this->Name, "n", IntToString(mN), IntToString(n));
	} else {
		for(GLsizei i = 0; i < n; ++i) {
			textures[i] = mTextures[i];
		}
	}
}

extern "C" {
	DLL_EXPORT void CALL_CONV glGenTextures(GLsizei n, GLuint* textures) {
		GLGenTextures* command = GLFramework::CastAndGet<GLGenTextures>("glGenTextures");
		if(command != NULL) {
			command->Eval(n, textures);
			delete command;
		}
	}
}
