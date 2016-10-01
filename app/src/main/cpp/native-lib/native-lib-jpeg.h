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

struct native_lib_jpeg_read_data {
    native_lib_jpeg_read_data(std::vector<unsigned char> &data)
            : _data(data) {
        _pos = 0;
    }

    std::vector<unsigned char> &_data;
    uint32_t _pos;
};

typedef struct native_lib_jpeg_error_mgr *native_lib_jpeg_error_mgr_ptr;

int native_lib_jpeg_Read(void *cookie, char *buf, int nbytes);

jobject native_lib_jpeg_ParseRGB(JNIEnv *env, jpeg_decompress_struct &cinfo);

jobject native_lib_jpeg_Load(JNIEnv *env, jobject inputStream);

#endif //OCRLAB_NATIVE_LIB_JPEG_H
