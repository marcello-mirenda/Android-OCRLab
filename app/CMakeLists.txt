# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             com-reviso-marcello-ocrlab-z

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.

             src/main/cpp/z/crc32.c
             src/main/cpp/z/deflate.c
             src/main/cpp/z/gzwrite.c
             src/main/cpp/z/gzread.c
             src/main/cpp/z/gzclose.c
             src/main/cpp/z/infback.c
             src/main/cpp/z/gzlib.c
             src/main/cpp/z/inffast.c
             src/main/cpp/z/zutil.c
             src/main/cpp/z/uncompr.c
             src/main/cpp/z/inflate.c
             src/main/cpp/z/trees.c
             src/main/cpp/z/adler32.c
             src/main/cpp/z/inftrees.c
             src/main/cpp/z/compress.c
             src/main/cpp/z/crc32.c
             src/main/cpp/z/deflate.c
             src/main/cpp/z/gzwrite.c
             src/main/cpp/z/gzread.c
             src/main/cpp/z/gzclose.c
             src/main/cpp/z/infback.c
             src/main/cpp/z/gzlib.c
             src/main/cpp/z/inffast.c
             src/main/cpp/z/zutil.c
             src/main/cpp/z/uncompr.c
             src/main/cpp/z/inflate.c
             src/main/cpp/z/trees.c
             src/main/cpp/z/adler32.c
             src/main/cpp/z/inftrees.c
             src/main/cpp/z/compress.c
 )

add_library( # Sets the name of the library.
             com-reviso-marcello-ocrlab-png

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.

             src/main/cpp/png/pngpread.c
             src/main/cpp/png/png.c
             src/main/cpp/png/pngrio.c
             src/main/cpp/png/pngset.c
             src/main/cpp/png/pngerror.c
             src/main/cpp/png/pngrtran.c
             src/main/cpp/png/pngwtran.c
             src/main/cpp/png/pngwutil.c
             src/main/cpp/png/pngvcrd.c
             src/main/cpp/png/pnggccrd.c
             src/main/cpp/png/pngmem.c
             src/main/cpp/png/pngrutil.c
             src/main/cpp/png/pngread.c
             src/main/cpp/png/pngtrans.c
             src/main/cpp/png/pngwio.c
             src/main/cpp/png/pngwrite.c
             src/main/cpp/png/pngget.c
             src/main/cpp/png/pngtest.c
             src/main/cpp/png/example.c
 )

add_library( # Sets the name of the library.
             com-reviso-marcello-ocrlab-jpeg

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.

            src/main/cpp/jpeg/jaricom.c
            src/main/cpp/jpeg/jcapimin.c
            src/main/cpp/jpeg/jcapistd.c
            src/main/cpp/jpeg/jcarith.c
            src/main/cpp/jpeg/jccoefct.c
            src/main/cpp/jpeg/jccolor.c
            src/main/cpp/jpeg/jcdctmgr.c
            src/main/cpp/jpeg/jchuff.c
            src/main/cpp/jpeg/jcinit.c
            src/main/cpp/jpeg/jcmainct.c
            src/main/cpp/jpeg/jcmarker.c
            src/main/cpp/jpeg/jcmaster.c
            src/main/cpp/jpeg/jcomapi.c
            src/main/cpp/jpeg/jcparam.c
            src/main/cpp/jpeg/jcphuff.c
            src/main/cpp/jpeg/jcprepct.c
            src/main/cpp/jpeg/jcsample.c
            src/main/cpp/jpeg/jctrans.c
            src/main/cpp/jpeg/jdapimin.c
            src/main/cpp/jpeg/jdapistd.c
            src/main/cpp/jpeg/jdarith.c
            src/main/cpp/jpeg/jdatadst.c
            src/main/cpp/jpeg/jdatasrc.c
            src/main/cpp/jpeg/jdcoefct.c
            src/main/cpp/jpeg/jdcolor.c
            src/main/cpp/jpeg/jddctmgr.c
            src/main/cpp/jpeg/jdhuff.c
            src/main/cpp/jpeg/jdinput.c
            src/main/cpp/jpeg/jdmainct.c
            src/main/cpp/jpeg/jdmarker.c
            src/main/cpp/jpeg/jdmaster.c
            src/main/cpp/jpeg/jdmerge.c
            src/main/cpp/jpeg/jdphuff.c
            src/main/cpp/jpeg/jdpostct.c
            src/main/cpp/jpeg/jdsample.c
            src/main/cpp/jpeg/jdtrans.c
            src/main/cpp/jpeg/jerror.c
            src/main/cpp/jpeg/jfdctflt.c
            src/main/cpp/jpeg/jfdctfst.c
            src/main/cpp/jpeg/jfdctint.c
            src/main/cpp/jpeg/jidctflt.c
            src/main/cpp/jpeg/jidctfst.c
            src/main/cpp/jpeg/jidctint.c
            src/main/cpp/jpeg/jidctred.c
            src/main/cpp/jpeg/jmemmgr.c
            src/main/cpp/jpeg/jmemnobs.c
            src/main/cpp/jpeg/jquant1.c
            src/main/cpp/jpeg/jquant2.c
            src/main/cpp/jpeg/jutils.c
            src/main/cpp/jpeg/jsimd_none.c
 )

add_library( # Sets the name of the library.
             com-reviso-marcello-ocrlab-tiff

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.

            src/main/cpp/tiff/tif_aux.c
            src/main/cpp/tiff/tif_close.c
            src/main/cpp/tiff/tif_codec.c
            src/main/cpp/tiff/tif_color.c
            src/main/cpp/tiff/tif_compress.c
            src/main/cpp/tiff/tif_dir.c
            src/main/cpp/tiff/tif_dirinfo.c
            src/main/cpp/tiff/tif_dirread.c
            src/main/cpp/tiff/tif_dirwrite.c
            src/main/cpp/tiff/tif_dumpmode.c
            src/main/cpp/tiff/tif_error.c
            src/main/cpp/tiff/tif_extension.c
            src/main/cpp/tiff/tif_fax3.c
            src/main/cpp/tiff/tif_fax3sm.c
            src/main/cpp/tiff/tif_flush.c
            src/main/cpp/tiff/tif_getimage.c
            src/main/cpp/tiff/tif_jbig.c
            src/main/cpp/tiff/tif_jpeg_12.c
            src/main/cpp/tiff/tif_jpeg.c
            src/main/cpp/tiff/tif_luv.c
            src/main/cpp/tiff/tif_lzma.c
            src/main/cpp/tiff/tif_lzw.c
            src/main/cpp/tiff/tif_next.c
            src/main/cpp/tiff/tif_ojpeg.c
            src/main/cpp/tiff/tif_open.c
            src/main/cpp/tiff/tif_packbits.c
            src/main/cpp/tiff/tif_pixarlog.c
            src/main/cpp/tiff/tif_predict.c
            src/main/cpp/tiff/tif_print.c
            src/main/cpp/tiff/tif_read.c
            src/main/cpp/tiff/tif_strip.c
            src/main/cpp/tiff/tif_swab.c
            src/main/cpp/tiff/tif_thunder.c
            src/main/cpp/tiff/tif_tile.c
            src/main/cpp/tiff/tif_unix.c
            src/main/cpp/tiff/tif_version.c
            src/main/cpp/tiff/tif_warning.c
            src/main/cpp/tiff/tif_write.c
            src/main/cpp/tiff/tif_zip.c
            src/main/cpp/tiff/tif_stream.cxx
 )

add_library( # Sets the name of the library.
             com-reviso-marcello-ocrlab-native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/native-lib/native-lib.cpp
             src/main/cpp/native-lib/native-lib-common.cpp
             src/main/cpp/native-lib/native-lib-tiff.cpp
             src/main/cpp/native-lib/native-lib-png.cpp
             src/main/cpp/native-lib/native-lib-jpeg.cpp)

# Specifies a path to native header files.
include_directories(
    src/main/cpp/z
    src/main/cpp/png
    src/main/cpp/jpeg
    src/main/cpp/tiff
    src/main/cpp/native-lib
    )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       com-reviso-marcello-ocrlab-tiff
                       com-reviso-marcello-ocrlab-z

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )

target_link_libraries( # Specifies the target library.
                       com-reviso-marcello-ocrlab-png
                       com-reviso-marcello-ocrlab-z

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )

target_link_libraries( # Specifies the target library.
                       com-reviso-marcello-ocrlab-native-lib
                       com-reviso-marcello-ocrlab-tiff
                       com-reviso-marcello-ocrlab-png
                       com-reviso-marcello-ocrlab-jpeg

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
