//
// Created by marcello on 01/10/16.
//

#include <sstream>
#include "native-lib-common.h"
#include "native-lib-tiff.h"
#include "tiffio.h"
#include "tiffio.hxx"

jobject native_lib_tiff_Load(JNIEnv *env, jobject inputStream) {

    jint count = native_lib_AvailableData(env, inputStream);

    std::vector<unsigned char> buffer = std::vector<unsigned char>((unsigned long) count);
    native_lib_LoadData(env, inputStream, count, buffer);

    std::stringstream input_TIFF_stream;
    std::copy(buffer.begin(), buffer.end(), std::ostreambuf_iterator<char>(input_TIFF_stream));

    TIFF* mem_TIFF = TIFFStreamOpen("MemTIFF", (std::istream *)&input_TIFF_stream);

    unsigned long width, height;
    int status = TIFFGetField(mem_TIFF, TIFFTAG_IMAGEWIDTH, &width);
    status = TIFFGetField(mem_TIFF, TIFFTAG_IMAGELENGTH, &height);

    TIFFClose(mem_TIFF);

    return NULL;
}
