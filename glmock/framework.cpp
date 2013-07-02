#include "framework.h"
#include "impl/gl_framework.h"
#include <sstream>

namespace glmock
{
	//
	// The default error callback listener. This will cause the exception {@code glmock::IMockException} to be thrown
	// with the complete information regarding all the errors if any error where raised.
	class ExceptionErrorCallback : public IErrorCallback
	{
	public:
		ExceptionErrorCallback();
		virtual ~ExceptionErrorCallback();

	public:
		virtual void OnFunctionNotCalled(const char* expected);
		virtual void OnBadParameter(const char* function, const char* name, const char* expected, const char* actual);
		virtual void OnBadFunctionCalled(const char* expected, const char* actual);
		virtual void OnUnspecifiedFunctionCalled(const char* expected);

	private:
		std::vector<CommandError> mErrors;
	};

	///////////////////////////////////////////////////////////////////

	ExceptionErrorCallback::ExceptionErrorCallback()
	{
	}

	ExceptionErrorCallback::~ExceptionErrorCallback()
	{
		if(!mErrors.empty()) {
			CommandError* errors = new CommandError[mErrors.size()];
			for(size_t i = 0; i < mErrors.size(); ++i) {
				memcpy(&errors[i], &mErrors[i], sizeof(CommandError));
			}

			throw ValidationException(errors, mErrors.size());
		}
	}

	void ExceptionErrorCallback::OnFunctionNotCalled(const char* expected)
	{
		// Expected function 'glGetError' to be called, but wasn't
		char tmp[512] = {0};
		sprintf(tmp, "Expected function '%s' to be called, but wasn't", expected);

		CommandError cmd;
		strcpy_s(cmd.Command, 50, expected);
		strcpy_s(cmd.Error, 512, tmp);
		mErrors.push_back(cmd);
	}

	void ExceptionErrorCallback::OnBadParameter(const char* function, const char* name, const char* expected, const char* actual)
	{
		// Parameter 'sfactor' on function 'glTexParameteri' expected to be 'GL_NONE', but was 'GL_SRC_ALPHA'
		char tmp[512] = {0};
		sprintf(tmp, "Parameter '%s' on function '%s' expected to be '%s', but was '%s'", name, function, expected, actual);

		CommandError cmd;
		strcpy_s(cmd.Command, 50, function);
		strcpy_s(cmd.Error, 512, tmp);
		mErrors.push_back(cmd);
	}

	void ExceptionErrorCallback::OnBadFunctionCalled(const char* expected, const char* actual)
	{
		// Expected function 'glGetError', but was 'glGenTextures'
		char tmp[512] = {0};
		sprintf(tmp, "Expected function '%s', but was '%s'", expected, actual);

		CommandError cmd;
		strcpy_s(cmd.Command, 50, expected);
		strcpy_s(cmd.Error, 512, tmp);
		mErrors.push_back(cmd);
	}

	void ExceptionErrorCallback::OnUnspecifiedFunctionCalled(const char* expected)
	{
		// Expected function 'glGetError' but no function call has been registered
		char tmp[512] = {0};
		sprintf(tmp, "Expected function '%s' but no function call has been registered", expected);

		CommandError cmd;
		strcpy_s(cmd.Command, 50, expected);
		strcpy_s(cmd.Error, 512, tmp);
		mErrors.push_back(cmd);
	}

	///////////////////////////////////////////////////////////////////
	IFramework* Create()
	{
		return new GLFramework(new ExceptionErrorCallback());
	}
	
	IFramework* Create(IErrorCallback* callback)
	{
		return new GLFramework(callback);
	}

	void Destroy(IFramework* framework)
	{
		delete framework;
	}

}