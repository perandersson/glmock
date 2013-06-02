#include "gl_framework.h"
using namespace glmock;

GLFramework* __instance = 0;

GLFramework::GLFramework()
{
	__instance = this;
}

GLFramework::~GLFramework()
{
	__instance = 0;
	if(mCommands.size() > 0) {
		// Not all commands where invoked!!!
		while(!mCommands.empty()) {
			ICommand* cmd = mCommands.front();
			AddCommandError(cmd, "Expected to be called but wasn't");
			mCommands.pop();
		}
	}

	if(!mErrors.empty()) {
		CommandError* errors = new CommandError[mErrors.size()];
		for(size_t i = 0; i < mErrors.size(); ++i) {
			memcpy(&errors[i], &mErrors[i], sizeof(CommandError));
		}

		throw MockException(errors, mErrors.size());
	}
}

GLFramework& GLFramework::Get()
{
	return *__instance;
}

GLDeleteTextures* GLFramework::glDeleteTextures(GLsizei n, const GLuint* textures)
{
	GLDeleteTextures* command = new GLDeleteTextures(n, textures);
	mCommands.push(command);
	return command;
}

GLBindTexture* GLFramework::glBindTexture(GLenum target, GLuint texture)
{
	GLBindTexture* command = new GLBindTexture(target, texture);
	mCommands.push(command);
	return command;
}

GLGetError* GLFramework::glGetError()
{
	GLGetError* command = new GLGetError();
	mCommands.push(command);
	return command;
}

void GLFramework::AddCommandError(ICommand* command, const char* error)
{
	CommandError cmderr;
	strcpy_s(cmderr.Command, 50, typeid(*command).name());
	strcpy_s(cmderr.Error, 128, error);
	mErrors.push_back(cmderr);
}

