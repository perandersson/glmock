#include "gl_strings.h"

namespace glmock
{
	const char* EnumToString(FuncTypes func, GLenum value)
	{
		const char* str = 0;
		if(func == GL_TEX_IMAGE_2D) {
			switch(value)
			{
			case GL_UNSIGNED_BYTE: str = AS_STRING(GL_UNSIGNED_BYTE); break;
			case GL_BYTE: str = AS_STRING(GL_BYTE); break;
			case GL_UNSIGNED_SHORT: str = AS_STRING(GL_UNSIGNED_SHORT); break;
			case GL_SHORT: str = AS_STRING(GL_SHORT); break;
			case GL_UNSIGNED_INT: str = AS_STRING(GL_UNSIGNED_INT); break;
			case GL_INT: str = AS_STRING(GL_INT); break;
			case GL_FLOAT: str = AS_STRING(GL_FLOAT); break;
			case GL_UNSIGNED_BYTE_3_3_2: str = AS_STRING(GL_UNSIGNED_BYTE_3_3_2); break;
			case GL_UNSIGNED_BYTE_2_3_3_REV: str = AS_STRING(GL_UNSIGNED_BYTE_2_3_3_REV); break;
			case GL_UNSIGNED_SHORT_5_6_5: str = AS_STRING(GL_UNSIGNED_SHORT_5_6_5); break;
			case GL_UNSIGNED_SHORT_5_6_5_REV: str = AS_STRING(GL_UNSIGNED_SHORT_5_6_5_REV); break;
			case GL_UNSIGNED_SHORT_4_4_4_4: str = AS_STRING(GL_UNSIGNED_SHORT_4_4_4_4); break;
			case GL_UNSIGNED_SHORT_4_4_4_4_REV: str = AS_STRING(GL_UNSIGNED_SHORT_4_4_4_4_REV); break;
			case GL_UNSIGNED_SHORT_5_5_5_1: str = AS_STRING(GL_UNSIGNED_SHORT_5_5_5_1); break;
			case GL_UNSIGNED_SHORT_1_5_5_5_REV: str = AS_STRING(GL_UNSIGNED_SHORT_1_5_5_5_REV); break;
			case GL_UNSIGNED_INT_8_8_8_8: str = AS_STRING(GL_UNSIGNED_INT_8_8_8_8); break;
			case GL_UNSIGNED_INT_8_8_8_8_REV: str = AS_STRING(GL_UNSIGNED_INT_8_8_8_8_REV); break;
			case GL_UNSIGNED_INT_10_10_10_2: str = AS_STRING(GL_UNSIGNED_INT_10_10_10_2); break;
			case GL_UNSIGNED_INT_2_10_10_10_REV: str = AS_STRING(GL_UNSIGNED_INT_2_10_10_10_REV); break;
		
			case GL_RED: str = AS_STRING(GL_RED); break;
			case GL_RG: str = AS_STRING(GL_RG); break;
			case GL_RGB: str = AS_STRING(GL_RGB); break;
			case GL_BGR: str = AS_STRING(GL_BGR); break;
			case GL_RGBA: str = AS_STRING(GL_RGBA); break;
			case GL_BGRA: str = AS_STRING(GL_BGRA); break;

			default: str = AS_STRING(UNKNOWN); str = AS_STRING(UNKNOWN); break;
			};
		} else if(func == GL_BIND_TEXTURE) {
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
		}
		return str;
	}
}
