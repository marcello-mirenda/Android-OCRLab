//
// Created by marcello on 07/10/16.
//

#include <vector>
#include "native-lib-common.h"
#include "native-lib-jpeg.h"
#include "allheaders.h"
#include "native-lib-lept.h"

jobject native_lib_lept_Rotate(JNIEnv *env, jobject inputStream) {
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

    if (pixs->informat != IFF_JFIF_JPEG) {
        pixDestroy(&pixs);
        return NULL;
    }

    l_int32 w, h, d, rotflag;
    l_float32 ang, deg2rad;
    rotflag = L_ROTATE_AREA_MAP;
/*    rotflag = L_ROTATE_SHEAR;     */
/*    rotflag = L_ROTATE_SAMPLING;   */
    deg2rad = 3.1415926535f / 180.f;
    ang = 90.0f * deg2rad;
    pixGetDimensions(pixs, &w, &h, NULL);
    PIX *pixd = pixRotate(pixs, ang, rotflag, L_BRING_IN_WHITE, w, h);

    pixWriteStream(infile, pixd, pixs->informat);

    pixDestroy(&pixs);
    pixDestroy(&pixd);

    return native_lib_jpeg_Load(env, buffer);
}

