#include "glDeleteTextures.h"
#include "../gl_framework.h"
#include <memory>
using namespace glmock;

GLDeleteTextures::GLDeleteTextures() : mExpect(0), mResult(0)
{
}

GLDeleteTextures::~GLDeleteTextures()
{
}

GLDeleteTextures* GLDeleteTextures::Expect(GLsizei n)
{
	mExpect = n;
	return this;
}

void GLDeleteTextures::Result(const GLuint* textures)
{
	mResult = textures;
}

void GLDeleteTextures::Eval(GLsizei n, const GLuint* textures)
{
	if(mExpect != n) {
		// Fatal error!!!
	}

	memcpy(const_cast<GLuint*>(textures), mResult, mExpect);
}

extern "C" {
	DLL_EXPORT void GL_FUNCTION(glDeleteTextures)(GLsizei n, const GLuint* textures) {
		GLDeleteTextures* command = GLFramework::Get().CastAndGet<GLDeleteTextures>();
		if(command != NULL) {
			command->Eval(n, textures);
			delete command;
		}
	}
}
