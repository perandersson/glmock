#pragma once
#define GLEW_BUILD

// Add more types here later
#ifdef EXPORT_DLL
#define DLL_EXPORT __declspec(dllexport)
#define CALL_CONV __stdcall 
#else
#define DLL_EXPORT __declspec(dllimport)
#define CALL_CONV __stdcall 
#endif
#define WINGDIAPI DLL_EXPORT
#include <gl/glew.h>

// Add more types here later
#ifdef EXPORT_DLL
#define DLL_EXPORT __declspec(dllexport)
#define CALL_CONV __stdcall 
#else
#define DLL_EXPORT __declspec(dllimport)
#define CALL_CONV __stdcall 
#endif
