//
// Created by marcello on 01/10/16.
//

#include "native-lib-common.h"
#include "native-lib-png.h"

jobject native_lib_png_Load(JNIEnv *env, jobject inputStream) {

    jint count = native_lib_AvailableData(env, inputStream);

    std::vector<unsigned char> buffer = std::vector<unsigned char>((unsigned long) count);
    native_lib_LoadData(env, inputStream, count, buffer);

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
    png_set_read_fn(png_ptr, &iterator, native_lib_png_ReadDataFromInputStream);

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
            bitmap = native_lib_png_ParseRGB(env, width, height, png_ptr, info_ptr, false);
            break;

        case PNG_COLOR_TYPE_RGB_ALPHA:
            bitmap = native_lib_png_ParseRGB(env, width, height, png_ptr, info_ptr, true);
            break;
        case PNG_COLOR_TYPE_GRAY:
            bitmap = NULL;
            break;
        case PNG_COLOR_TYPE_GRAY_ALPHA:
            bitmap = NULL;
            break;
        case PNG_COLOR_TYPE_PALETTE:
            png_set_palette_to_rgb(png_ptr);
            bitmap = native_lib_png_ParseRGB(env, width, height, png_ptr, info_ptr, false);
            break;
        default:
            bitmap = NULL;
            break;
    }

    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    return bitmap;
}

void native_lib_png_ReadDataFromInputStream(png_structp png_ptr, png_bytep outBytes,
                                            png_size_t byteCountToRead) {
    png_voidp io_ptr = png_get_io_ptr(png_ptr);
    if (io_ptr == NULL)
        return; // add custom error handling here

    std::vector<unsigned char>::iterator *iterator = (std::vector<unsigned char>::iterator *) io_ptr;

    for (int i = 0; i < byteCountToRead; ++i) {
        outBytes[i] = iterator->operator*();
        iterator->operator++();
    }
}

jobject native_lib_png_ParseRGB(JNIEnv *env, const png_uint_32 width, const png_uint_32 height,
                                const png_structp &png_ptr, const png_infop &info_ptr,
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
            colors[colorIndex++] = (alphaChannel ? (rowData[byteIndex + 3] << 24) : 0xFF000000) |
                                   (rowData[byteIndex] << 16) |
                                   (rowData[byteIndex + 1] << 8) |
                                   rowData[byteIndex + 2];
            byteIndex += alphaChannel ? 4 : 3;
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
