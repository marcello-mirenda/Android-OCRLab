//
// Created by marcello on 28/10/16.
//

#include <vector>
#include <api/baseapi.h>
#include <allheaders.h>
#include <android/log.h>
#include "native-lib-common.h"
#include "native-lib-tesseract.h"

using namespace tesseract;

jobject native_lib_recognize(JNIEnv *env, jstring tessDataPath, jobject inputStream) {

    jint count = native_lib_AvailableData(env, inputStream);
    std::vector<unsigned char> buffer = std::vector<unsigned char>((unsigned long) count);
    native_lib_LoadData(env, inputStream, count, buffer);
    native_lib_read_data rd(buffer);
    FILE *infile;
    if ((infile = funopen(&rd, native_lib_read_fn, native_lib_write_fn, native_lib_lseek_fn, 0)) ==
        NULL) {
        return NULL;
    }
    PIX *pixs;
    if ((pixs = pixReadStream(infile, 0)) == NULL) {
        return NULL;
    }

    TessBaseAPI api;

    const char* path = env->GetStringUTFChars(tessDataPath, JNI_FALSE);
    api.Init(path, "ita");
    api.SetImage(pixs);
    auto text = api.GetUTF8Text();

    __android_log_print(ANDROID_LOG_INFO, "OCRLAB", "text:%s", text);

    delete [] text;
    pixDestroy(&pixs);

    return 0;
}
