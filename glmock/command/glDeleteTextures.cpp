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
		char expected[10] = {0};
		char actual[10] = {0};
		itoa(mN, expected, 10);
		itoa(n, actual, 10);
		GLFramework::OnBadParameter(this, "n", expected, actual);
	} else {
		for(GLsizei i = 0; i < n; ++i) {
			if(textures[i] != mTextures[i]) {
				GLFramework::OnBadParameter(this, "textures", "[...]", "[...]");
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
