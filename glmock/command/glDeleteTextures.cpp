#include "glDeleteTextures.h"
#include "../glmock.h"
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
	void GL_FUNCTION(glDeleteTextures)(GLsizei n, const GLuint* textures) {
		GLDeleteTextures* command = GLMock::Get().CastAndGet<GLDeleteTextures>();
		if(command != NULL) {
			command->Eval(n, textures);
		} else {
			GLMock::Get().AddCommandError("glDeleteTextures", "");
		}
	}
}
