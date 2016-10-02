//
// Created by marcello on 01/10/16.
//

#ifndef OCRLAB_NATIVE_LIB_COMMON_H
#define OCRLAB_NATIVE_LIB_COMMON_H

#include <jni.h>
#include <vector>
#include <cstdint>

struct native_lib_read_data {
    native_lib_read_data(std::vector<unsigned char> &data)
            : _data(data) {
        _pos = 0;
    }

    std::vector<unsigned char> &_data;
    uint32_t _pos;
};

int native_lib_read_fn(void *cookie, char *buf, int nbytes);

jint native_lib_AvailableData(JNIEnv *env, jobject inputStream);

jint native_lib_LoadData(JNIEnv *env, jobject inputStream, jint count,
                         std::vector<unsigned char> &buffer);

#endif //OCRLAB_NATIVE_LIB_COMMON_H
