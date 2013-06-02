#include "glDeleteTextures.h"
#include "../gl_framework.h"
#include <memory>
using namespace glmock;

GLDeleteTextures::GLDeleteTextures(GLsizei n, const GLuint* textures) : mN(n), mTextures(textures)
{
}

GLDeleteTextures::~GLDeleteTextures()
{
}

void GLDeleteTextures::Eval(GLsizei n, const GLuint* textures)
{
	if(mN != n) {
		GLFramework::Get().AddCommandError(this, "Parameter 'n' is invalid");
	} else {
		for(GLsizei i = 0; i < n; ++i) {
			if(textures[i] != mTextures[i]) {
				GLFramework::Get().AddCommandError(this, "Parameter 'textures' is invalid");
				return;
			}
		}
	}
}

extern "C" {
	DLL_EXPORT void CALL_CONV glDeleteTextures(GLsizei n, const GLuint* textures) {
		GLDeleteTextures* command = GLFramework::Get().CastAndGet<GLDeleteTextures>();
		if(command != NULL) {
			command->Eval(n, textures);
			delete command;
		}
	}
}
