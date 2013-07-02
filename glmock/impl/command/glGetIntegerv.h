#pragma once

#include "../gl_command.h"
#include "../gl_strings.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glGetIntegerv.xml
	class GLGetIntegerv : public GLCommand
	{
	public:
		GLGetIntegerv(GLenum pname, GLint *params);
		virtual ~GLGetIntegerv();

		static const char* EnumToString(GLenum value) {
			const char* str = 0;
			switch(value)
			{
			case GL_TEXTURE_BINDING_2D: str = AS_STRING(GL_TEXTURE_BINDING_2D); break;
			default: str = AS_STRING(UNKNOWN); break;
			};
			return str;
		}
		
	public:
		void Eval(GLenum pname, GLint *params);

	private:
		GLenum mPname;
		GLint *mParams;
	};
}
