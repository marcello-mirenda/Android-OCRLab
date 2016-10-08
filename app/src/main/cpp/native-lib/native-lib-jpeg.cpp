//
// Created by marcello on 01/10/16.
//

#include "native-lib-common.h"
#include "native-lib-jpeg.h"

METHODDEF(void) native_lib_jpeg_error_exit(j_common_ptr cinfo);

jobject native_lib_jpeg_Load(JNIEnv *env, jobject inputStream) {

    jint count = native_lib_AvailableData(env, inputStream);

    std::vector<unsigned char> buffer = std::vector<unsigned char>((unsigned long) count);
    native_lib_LoadData(env, inputStream, count, buffer);

    return native_lib_jpeg_Load(env, buffer);
}

jobject native_lib_jpeg_Load(JNIEnv *env, std::vector<unsigned char> &buffer) {

    native_lib_read_data rd(buffer);
    FILE *infile;
    if ((infile = fropen(&rd, native_lib_read_fn)) == NULL) {
        return NULL;
    }

    struct jpeg_decompress_struct cinfo;
    struct native_lib_jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = native_lib_jpeg_error_exit;
    if (setjmp(jerr.setjmp_buffer)) {
        jpeg_destroy_decompress(&cinfo);
        // fclose(infile);
        return NULL;
    }
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    (void) jpeg_read_header(&cinfo, TRUE);
    cinfo.scale_num = 1;
    cinfo.scale_denom = 4;
    (void) jpeg_start_decompress(&cinfo);
    jobject bitmap = NULL;
    switch (cinfo.out_color_space) {
        case JCS_RGB:
            bitmap = native_lib_jpeg_ParseRGB(env, cinfo);
            break;
        default:
            bitmap = NULL;
            break;
    }
    (void) jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    // fclose(infile);
    return bitmap;
}

jobject native_lib_jpeg_ParseRGB(JNIEnv *env, jpeg_decompress_struct &cinfo) {

    std::vector<int> colors = std::vector<int>(cinfo.output_width * cinfo.output_height);
    JDIMENSION row_stride = cinfo.output_width * cinfo.output_components;
    JSAMPARRAY rowData = (*cinfo.mem->alloc_sarray)((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride,
                                                    1);

    int cols = cinfo.output_width;
    int colorIndex = 0;
    while (cinfo.output_scanline < cinfo.output_height) {

        (void) jpeg_read_scanlines(&cinfo, rowData, 1);
        int byteIndex = 0;
        for (int col = 0; col < cols; ++col) {
            colors[colorIndex++] = 0xFF000000 | (rowData[0][byteIndex] << 16) |
                                   (rowData[0][byteIndex + 1] << 8) |
                                   rowData[0][byteIndex + 2];
            byteIndex += 3;
        }
    }

    return native_lib_CreateBitmap(env, (jint) cinfo.output_width, (jint) cinfo.output_height,
                                   colors);
}

METHODDEF(void) native_lib_jpeg_error_exit(j_common_ptr cinfo) {
    /* cinfo->err really points to a my_error_mgr struct, so coerce pointer */
    native_lib_jpeg_error_mgr_ptr err = (native_lib_jpeg_error_mgr_ptr) cinfo->err;

    /* Always display the message. */
    /* We could postpone this until after returning, if we chose. */
    (*cinfo->err->output_message)(cinfo);

    /* Return control to the setjmp point */
    longjmp(err->setjmp_buffer, 1);
}
