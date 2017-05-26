//
// Created by marcello on 01/10/16.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

int native_lib_read_fn(void *cookie, char *buf, int nbytes) {
    native_lib_read_data *prd = (native_lib_read_data *) cookie;

    int i;
    for (i = 0; i < nbytes && prd->_pos < prd->_data.size(); ++i) {
        buf[i] = prd->_data[prd->_pos++];
    }
    return i;
}

int native_lib_write_fn(void *cookie, const char *buf, int nbytes) {
    native_lib_read_data *prd = (native_lib_read_data *) cookie;

    int i;
    for (i = 0; i < nbytes && prd->_pos < prd->_data.size(); ++i) {
        prd->_data[prd->_pos++] = buf[i];
    }
    return i;
}

fpos_t native_lib_lseek_fn(void *cookie, fpos_t offset, int whence) {
    native_lib_read_data *prd = (native_lib_read_data *) cookie;
    switch (whence) {
        case SEEK_SET:
            prd->_pos = offset;
            break;
        case SEEK_CUR:
            prd->_pos += offset;
            break;
        case SEEK_END:
            prd->_pos = prd->_data.size() + offset;
            break;
    }
    return prd->_pos;
}


jobject native_lib_CreateBitmap(JNIEnv *env, jint width, jint height, std::vector<jint> &colors) {

    // static Bitmap createBitmap(int[] colors, int width, int height, Bitmap.Config config)

    jclass bitMapConfigClass = env->FindClass("android/graphics/Bitmap$Config");
    jfieldID argbField = env->GetStaticFieldID(bitMapConfigClass, "ARGB_8888",
                                               "Landroid/graphics/Bitmap$Config;");
    jobject ARGB = env->GetStaticObjectField(bitMapConfigClass, argbField);
    jclass bitMapClass = env->FindClass("android/graphics/Bitmap");
    jmethodID createBitmapMethod = env->GetStaticMethodID(bitMapClass, "createBitmap",
                                                          "([IIILandroid/graphics/Bitmap$Config;)Landroid/graphics/Bitmap;");
    jintArray colorsArray = env->NewIntArray((jsize) colors.size());
    env->SetIntArrayRegion(colorsArray, 0, (jsize) colors.size(), colors.data());
    return env->CallStaticObjectMethod(bitMapClass, createBitmapMethod, colorsArray,
                                       width, height, ARGB);
}
