//
// Created by marcello on 01/10/16.
//

#ifndef OCRLAB_NATIVE_LIB_JPEG_H
#define OCRLAB_NATIVE_LIB_JPEG_H

#include <jni.h>
#include <stdio.h>
#include <setjmp.h>
#include <stdint.h>
#include <vector>
#include "jpeglib.h"

struct native_lib_jpeg_error_mgr {
    struct jpeg_error_mgr pub;
    jmp_buf setjmp_buffer;
};

typedef struct native_lib_jpeg_error_mgr *native_lib_jpeg_error_mgr_ptr;

jobject native_lib_jpeg_ParseRGB(JNIEnv *env, jpeg_decompress_struct &cinfo);

jobject native_lib_jpeg_Load(JNIEnv *env, jobject inputStream);

#endif //OCRLAB_NATIVE_LIB_JPEG_H
