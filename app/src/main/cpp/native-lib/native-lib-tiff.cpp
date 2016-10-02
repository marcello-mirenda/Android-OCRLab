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

    TIFF *mem_TIFF = TIFFStreamOpen("MemTIFF", (std::istream *) &input_TIFF_stream);

    uint32 w, h;
    size_t npixels;
    uint32 *raster;

    TIFFGetField(mem_TIFF, TIFFTAG_IMAGEWIDTH, &w);
    TIFFGetField(mem_TIFF, TIFFTAG_IMAGELENGTH, &h);
    npixels = w * h;
    std::vector<jint> colors = std::vector<jint>(npixels);
    raster = (uint32 *) _TIFFmalloc(npixels * sizeof(uint32));
    if (raster != NULL) {
        if (TIFFReadRGBAImage(mem_TIFF, w, h, raster, 0)) {

            uint32 colorIndex = 0;
            for (int r = (h - 1); r >= 0; --r) {
                for (int c = 0; c < w; ++c) {
                    uint8 *components = (uint8 *) (raster + (r * w) + c);
                    colors[colorIndex++] = (components[3] << 24) |
                                           (components[0] << 16) |
                                           (components[1] << 8) |
                                           components[2];

                }
            }
        }
        _TIFFfree(raster);
    }
    TIFFClose(mem_TIFF);

    return native_lib_CreateBitmap(env, w, h, colors);
}
