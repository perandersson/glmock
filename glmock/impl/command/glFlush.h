#pragma once

#include "../../command.h"
#include "../gl_strings.h"

namespace glmock
{
	//
	// http://www.opengl.org/sdk/docs/man3/xhtml/glFlush.xml
	class GLFlush : public ICommand
	{
	public:
		GLFlush();
		virtual ~GLFlush();
	};
}
