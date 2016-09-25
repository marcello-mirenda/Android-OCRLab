#include <jni.h>
#include <string>
#include <vector>
#include <iostream>
#include "png.h"

jint availableData(JNIEnv *env, jobject inputStream);

jint loadData(JNIEnv *env, jobject inputStream, jint count, std::vector<unsigned char> &buffer);

void readDataFromInputStream(
        png_structp png_ptr,
        png_bytep outBytes,
        png_size_t byteCountToRead);

jobject ParseRGB(
        JNIEnv *env,
        const png_uint_32 width,
        const png_uint_32 height,
        const png_structp &png_ptr,
        const png_infop &info_ptr,
        bool alphaChannel);

jint GetColor(JNIEnv *env, const png_byte alpha, const png_byte red, const png_byte green,
              const png_byte blue);

extern "C"
jstring
Java_com_reviso_marcello_1ocrlab_ocrlab_MainActivity_pngLibVersion(
        JNIEnv *env,
        jobject /* this */) {

    png_struct png;
    png_charp cr = png_get_copyright(&png);
    std::string msg(cr);
    return env->NewStringUTF(msg.c_str());
}

extern "C"
jobject
Java_com_reviso_marcello_1ocrlab_ocrlab_MainActivity_loadPng(
        JNIEnv *env,
        jobject /* this */,
        jobject inputStream) {

    jint count = availableData(env, inputStream);

    std::vector<unsigned char> buffer = std::vector<unsigned char>((unsigned long) count);
    loadData(env, inputStream, count, buffer);

    if (!png_check_sig(buffer.data(), 8))
        return NULL;

    // get PNG file info struct (memory is allocated by libpng)
    png_structp png_ptr = NULL;
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png_ptr == NULL)
        return NULL;

    // get PNG image data info struct (memory is allocated by libpng)
    png_infop info_ptr = NULL;
    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL) {
        // libpng must free file info struct memory before we bail
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        return NULL;
    }

    std::vector<unsigned char>::iterator iterator = buffer.begin();
    png_set_read_fn(png_ptr, &iterator, readDataFromInputStream);

    png_read_info(png_ptr, info_ptr);

    png_uint_32 width = 0;
    png_uint_32 height = 0;
    int bitDepth = 0;
    int colorType = -1;
    png_uint_32 retval = png_get_IHDR(png_ptr, info_ptr,
                                      &width,
                                      &height,
                                      &bitDepth,
                                      &colorType,
                                      NULL, NULL, NULL);

    if (retval != 1)
        return NULL;    // add error handling and cleanup

    jobject bitmap = NULL;
    switch (colorType) {
        case PNG_COLOR_TYPE_RGB:
            bitmap = ParseRGB(env, width, height, png_ptr, info_ptr, false);
            break;

        case PNG_COLOR_TYPE_RGB_ALPHA:
            bitmap = ParseRGB(env, width, height, png_ptr, info_ptr, true);
            break;
        default:
            bitmap = NULL;
            break;
    }

    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    return bitmap;
}

jint availableData(JNIEnv *env, jobject inputStream) {
    jclass fileInputStreamClass = env->GetObjectClass(inputStream);
    jmethodID availableMethod = env->GetMethodID(fileInputStreamClass, "available", "()I");
    return env->CallIntMethod(inputStream, availableMethod);
}

jint loadData(JNIEnv *env, jobject inputStream, jint count, std::vector<unsigned char> &buffer) {
    jbyteArray byteArray = env->NewByteArray(count);
    jclass fileInputStreamClass = env->GetObjectClass(inputStream);
    jmethodID readMethod = env->GetMethodID(fileInputStreamClass, "read", "([BII)I");
    jint ret = env->CallIntMethod(inputStream, readMethod, byteArray, 0, count);
    env->GetByteArrayRegion(byteArray, 0, count, (jbyte *) buffer.data());
    return ret;
}

void readDataFromInputStream(
        png_structp png_ptr,
        png_bytep outBytes,
        png_size_t byteCountToRead) {
    png_voidp io_ptr = png_get_io_ptr(png_ptr);
    if (io_ptr == NULL)
        return;   // add custom error handling here

    std::vector<unsigned char>::iterator *iterator = (std::vector<unsigned char>::iterator *) io_ptr;

    for (int i = 0; i < byteCountToRead; ++i) {
        outBytes[i] = iterator->operator*();
        iterator->operator++();
    }
}

jobject ParseRGB(
        JNIEnv *env,
        const png_uint_32 width,
        const png_uint_32 height,
        const png_structp &png_ptr,
        const png_infop &info_ptr,
        bool alphaChannel) {
    std::vector<jint> colors = std::vector<jint>(width * height);

    const png_uint_32 bytesPerRow = png_get_rowbytes(png_ptr, info_ptr);
    std::vector<png_byte> rowData = std::vector<png_byte>(bytesPerRow);
    // read single row at a time
    png_uint_32 colorIndex = 0;
    for (png_uint_32 rowIdx = 0; rowIdx < height; ++rowIdx) {
        png_read_row(png_ptr, (png_bytep) rowData.data(), NULL);


        png_uint_32 byteIndex = 0;
        for (png_uint_32 colIdx = 0; colIdx < width; ++colIdx) {
            const png_byte red = rowData[byteIndex++];
            const png_byte green = rowData[byteIndex++];
            const png_byte blue = rowData[byteIndex++];
            const png_byte alpha = (const png_byte) (alphaChannel ? rowData[byteIndex++] : 0);

            jint color = GetColor(env, alpha, red, green, blue);
            colors[colorIndex++] = color;
        }
    }

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
    jobject bitmap = env->CallStaticObjectMethod(bitMapClass, createBitmapMethod, colorsArray,
                                                 (jint) width, (jint) height, ARGB);

    return bitmap;
}

jint GetColor(JNIEnv *env, const png_byte alpha, const png_byte red, const png_byte green,
              const png_byte blue) {
    // static int argb(int alpha, int red, int green, int blue)
    static jclass colorClass = NULL;
    if (colorClass == NULL) {
        colorClass = env->FindClass("android/graphics/Color");
    }
    jmethodID argbMethod = env->GetStaticMethodID(colorClass, "argb", "(IIII)I");
    return env->CallStaticIntMethod(colorClass, argbMethod, (jint) alpha, (jint) red, (jint) green,
                                    (jint) blue);
}