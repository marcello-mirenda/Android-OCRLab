//
// Created by marcello on 01/10/16.
//

#include "native-lib-common.h"

jint native_lib_AvailableData(JNIEnv *env, jobject inputStream) {
    jclass fileInputStreamClass = env->GetObjectClass(inputStream);
    jmethodID availableMethod = env->GetMethodID(fileInputStreamClass, "available", "()I");
    return env->CallIntMethod(inputStream, availableMethod);
}

jint native_lib_LoadData(JNIEnv *env, jobject inputStream, jint count,
                         std::vector<unsigned char> &buffer) {
    jbyteArray byteArray = env->NewByteArray(count);
    jclass fileInputStreamClass = env->GetObjectClass(inputStream);
    jmethodID readMethod = env->GetMethodID(fileInputStreamClass, "read", "([BII)I");
    jint ret = env->CallIntMethod(inputStream, readMethod, byteArray, 0, count);
    env->GetByteArrayRegion(byteArray, 0, count, (jbyte *) buffer.data());
    return ret;
}


