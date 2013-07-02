#include "glDeleteTextures.h"
#include "../gl_framework.h"
#include <memory>
using namespace glmock;

GLDeleteTextures::GLDeleteTextures(GLsizei n, const GLuint* textures) 
	: GLCommand("glDeleteTextures"),
	mN(n), mTextures(textures)
{
}

GLDeleteTextures::~GLDeleteTextures()
{
}

void GLDeleteTextures::Eval(GLsizei n, const GLuint* textures)
{
	if(mN != n) {
		GLFramework::AddBadParameter(this->Name, "n", IntToString(mN), IntToString(n));
	} else {
		for(GLsizei i = 0; i < n; ++i) {
			if(textures[i] != mTextures[i]) {
				GLFramework::AddBadParameter(this->Name, "textures", "[...]", "[...]");
			}
		}
	}
}

extern "C" {
	DLL_EXPORT void CALL_CONV glDeleteTextures(GLsizei n, const GLuint* textures) {
		GLDeleteTextures* command = GLFramework::CastAndGet<GLDeleteTextures>("glDeleteTextures");
		if(command != NULL) {
			command->Eval(n, textures);
			delete command;
		}
	}
}
