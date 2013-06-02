#include "framework.h"
#include "gl_framework.h"

namespace glmock
{

	IFramework* Create()
	{
		return new GLFramework();
	}

	void Destroy(IFramework* framework)
	{
		delete framework;
	}

}