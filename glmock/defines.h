#pragma once

#if defined(__MINGW32__) || defined(__CYGWIN__)
	#define CALL_CONV __stdcall
#elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
	#define CALL_CONV __stdcall
#else
	#define CALL_CONV 
#endif

#ifdef EXPORT_DLL
	#ifdef WIN32
	#define DLL_EXPORT __declspec(dllexport)
	#define WINGDIAPI DLL_EXPORT
	#endif

	#define GLEW_BUILD
#else
	#define DLL_EXPORT __declspec(dllimport)
#endif

#include <gl/glew.h>