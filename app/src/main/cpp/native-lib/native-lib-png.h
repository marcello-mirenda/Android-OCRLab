//
// Created by marcello on 01/10/16.
//

#ifndef OCRLAB_NATIVE_LIB_PNG_H
#define OCRLAB_NATIVE_LIB_PNG_H

#include "jni.h"
#include "png.h"

void native_lib_png_ReadDataFromInputStream(png_structp png_ptr, png_bytep outBytes,
                                            png_size_t byteCountToRead);

jobject native_lib_png_ParseRGB(JNIEnv *env, const png_uint_32 width, const png_uint_32 height,
                                const png_structp &png_ptr, const png_infop &info_ptr,
                                bool alphaChannel);

jobject native_lib_png_Load(JNIEnv *env, jobject inputStream);

#endif //OCRLAB_NATIVE_LIB_PNG_H
