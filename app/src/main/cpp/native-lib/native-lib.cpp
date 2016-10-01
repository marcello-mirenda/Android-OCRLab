#include <jni.h>
#include <string>
#include "native-lib-png.h"
#include "native-lib-jpeg.h"

extern "C"
jobject Java_com_reviso_marcello_1ocrlab_ocrlab_MainActivity_loadJpeg(JNIEnv *env,
                                                                      jobject /* this */,
                                                                      jobject inputStream) {
    return native_lib_jpeg_Load(env, inputStream);
}

extern "C"
jstring
Java_com_reviso_marcello_1ocrlab_ocrlab_MainActivity_pngLibVersion(JNIEnv *env,
                                                                   jobject /* this */) {
    png_struct png;
    png_charp cr = png_get_copyright(&png);
    std::string msg(cr);
    return env->NewStringUTF(msg.c_str());
}

extern "C"
jobject
Java_com_reviso_marcello_1ocrlab_ocrlab_MainActivity_loadPng(JNIEnv *env, jobject /* this */,
                                                             jobject inputStream) {
    return native_lib_png_Load(env, inputStream);
}
