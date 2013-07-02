#pragma once

#include "../gl_command.h"
#include "../gl_strings.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glBindTexture.xml
	class GLBindTexture : public GLCommand
	{
	public:
		GLBindTexture(GLenum target, GLuint texture);
		virtual ~GLBindTexture();

		static const char* EnumToString(GLenum value) {
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
		
	public:
		void Eval(GLenum target, GLuint texture);

	private:
		GLenum mTarget;
		GLuint mTexture;
	};
}
