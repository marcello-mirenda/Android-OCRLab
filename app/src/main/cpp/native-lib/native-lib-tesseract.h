//
// Created by marcello on 28/10/16.
//

#ifndef OCRLAB_NATIVE_LIB_TESSERACT_H
#define OCRLAB_NATIVE_LIB_TESSERACT_H

#include <jni.h>

jobject native_lib_recognize(JNIEnv *env, jstring tessDataPath, jobject inputStream);

#endif //OCRLAB_NATIVE_LIB_TESSERACT_H
