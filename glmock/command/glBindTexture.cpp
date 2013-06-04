#include "glBindTexture.h"
#include "../gl_framework.h"
#include "../glmock.h"
using namespace glmock;

GLBindTexture::GLBindTexture(GLenum target, GLuint texture)
	: mTarget(target), mTexture(texture)
{
}

GLBindTexture::~GLBindTexture()
{
}

void GLBindTexture::Eval(GLenum target, GLuint texture)
{
	if(mTarget != target) {
		const char* actual = AsString(target);
		const char* expected = AsString(mTarget);
		GLFramework::OnBadParameter(this, "target", expected, actual);
	}

	if(mTexture != texture) {
		char expected[10] = {0};
		char actual[10] = {0};
		itoa(mTexture, expected, 10);
		itoa(texture, actual, 10);
		GLFramework::OnBadParameter(this, "texture", expected, actual);
	}
}

const char* GLBindTexture::AsString(const GLenum value)
{
	const char* str = 0;
	switch(value)
	{
	case GL_TEXTURE_1D: str = AS_STRING(GL_TEXTURE_1D); break;
	case GL_TEXTURE_2D: str = AS_STRING(GL_TEXTURE_2D); break;
	case GL_TEXTURE_3D: str = AS_STRING(GL_TEXTURE_3D); break;
	case GL_TEXTURE_1D_ARRAY: str = AS_STRING(GL_TEXTURE_1D_ARRAY); break;
	case GL_TEXTURE_2D_ARRAY: str = AS_STRING(GL_TEXTURE_2D_ARRAY); break;
	case GL_TEXTURE_RECTANGLE: str = AS_STRING(GL_TEXTURE_RECTANGLE); break;
	case GL_TEXTURE_CUBE_MAP: str = AS_STRING(GL_TEXTURE_CUBE_MAP); break;
	case GL_TEXTURE_BUFFER: str = AS_STRING(GL_TEXTURE_BUFFER); break;
	case GL_TEXTURE_2D_MULTISAMPLE: str = AS_STRING(GL_TEXTURE_2D_MULTISAMPLE); break;
	case GL_TEXTURE_2D_MULTISAMPLE_ARRAY: str = AS_STRING(GL_TEXTURE_2D_MULTISAMPLE_ARRAY); break;
	default: str = AS_STRING(UNKNOWN); break;
	};
	return str;
}

extern "C" {
	DLL_EXPORT void CALL_CONV glBindTexture(GLenum target, GLuint texture) {
		GLBindTexture* command = GLFramework::Get().CastAndGet<GLBindTexture>();
		if(command != NULL) {
			command->Eval(target, texture);
			delete command;
		}
	}
}
