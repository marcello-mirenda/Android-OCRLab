//
// Created by marcello on 01/10/16.
//

#ifndef OCRLAB_NATIVE_LIB_COMMON_H
#define OCRLAB_NATIVE_LIB_COMMON_H

#include <jni.h>
#include <vector>

jint native_lib_AvailableData(JNIEnv *env, jobject inputStream);

jint native_lib_LoadData(JNIEnv *env, jobject inputStream, jint count,
                         std::vector<unsigned char> &buffer);

#endif //OCRLAB_NATIVE_LIB_COMMON_H
