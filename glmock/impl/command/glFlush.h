#pragma once

#include "../gl_command.h"
#include "../gl_strings.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glFlush.xml
	class GLFlush : public GLCommand
	{
	public:
		GLFlush();
		virtual ~GLFlush();
	};
}
