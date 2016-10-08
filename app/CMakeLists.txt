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
             com-reviso-marcello-ocrlab-lept

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.

            src/main/cpp/lept/pixconv.c
            src/main/cpp/lept/ptafunc1.c
            src/main/cpp/lept/tiffiostub.c
            src/main/cpp/lept/quadtree.c
            src/main/cpp/lept/jbclass.c
            src/main/cpp/lept/adaptmap.c
            src/main/cpp/lept/pixtiling.c
            src/main/cpp/lept/convolve.c
            src/main/cpp/lept/sel1.c
            src/main/cpp/lept/arrayaccess.c
            src/main/cpp/lept/boxfunc2.c
            src/main/cpp/lept/bmpio.c
            src/main/cpp/lept/writefile.c
            src/main/cpp/lept/fhmtgen.1.c
            src/main/cpp/lept/numabasic.c
            src/main/cpp/lept/fmorphgenlow.1.c
            src/main/cpp/lept/bardecode.c
            src/main/cpp/lept/webpiostub.c
            src/main/cpp/lept/graphics.c
            src/main/cpp/lept/recogtrain.c
            src/main/cpp/lept/bmpiostub.c
            src/main/cpp/lept/kernel.c
            src/main/cpp/lept/dewarp4.c
            src/main/cpp/lept/xtractprotos.c
            src/main/cpp/lept/jpegio.c
            src/main/cpp/lept/pnmiostub.c
            src/main/cpp/lept/fhmtgenlow.1.c
            src/main/cpp/lept/dewarp3.c
            src/main/cpp/lept/psio2stub.c
            src/main/cpp/lept/finditalic.c
            src/main/cpp/lept/scale.c
            src/main/cpp/lept/grayquant.c
            src/main/cpp/lept/morphapp.c
            src/main/cpp/lept/encoding.c
            src/main/cpp/lept/libversions.c
            src/main/cpp/lept/bbuffer.c
            src/main/cpp/lept/bootnumgen2.c
            src/main/cpp/lept/pixabasic.c
            src/main/cpp/lept/viewfiles.c
            src/main/cpp/lept/ccbord.c
            src/main/cpp/lept/pageseg.c
            src/main/cpp/lept/projective.c
            src/main/cpp/lept/zlibmemstub.c
            src/main/cpp/lept/watershed.c
            src/main/cpp/lept/rotate.c
            src/main/cpp/lept/dwacomblow.2.c
            src/main/cpp/lept/morph.c
            src/main/cpp/lept/selgen.c
            src/main/cpp/lept/dnabasic.c
            src/main/cpp/lept/pixarith.c
            src/main/cpp/lept/readbarcode.c
            src/main/cpp/lept/pdfio2.c
            src/main/cpp/lept/recogbasic.c
            src/main/cpp/lept/numafunc1.c
            src/main/cpp/lept/pix3.c
            src/main/cpp/lept/rotateamlow.c
            src/main/cpp/lept/bilinear.c
            src/main/cpp/lept/bmf.c
            src/main/cpp/lept/seedfilllow.c
            src/main/cpp/lept/pdfio1stub.c
            src/main/cpp/lept/ptra.c
            src/main/cpp/lept/enhance.c
            src/main/cpp/lept/bytearray.c
            src/main/cpp/lept/maze.c
            src/main/cpp/lept/boxfunc4.c
            src/main/cpp/lept/morphseq.c
            src/main/cpp/lept/boxfunc1.c
            src/main/cpp/lept/jpegiostub.c
            src/main/cpp/lept/stringcode.c
            src/main/cpp/lept/affinecompose.c
            src/main/cpp/lept/baseline.c
            src/main/cpp/lept/stack.c
            src/main/cpp/lept/rbtree.c
            src/main/cpp/lept/morphdwa.c
            src/main/cpp/lept/fliphmtgen.c
            src/main/cpp/lept/pixalloc.c
            src/main/cpp/lept/regutils.c
            src/main/cpp/lept/colorquant2.c
            src/main/cpp/lept/coloring.c
            src/main/cpp/lept/pix4.c
            src/main/cpp/lept/colorcontent.c
            src/main/cpp/lept/jp2kheader.c
            src/main/cpp/lept/recogdid.c
            src/main/cpp/lept/rotateam.c
            src/main/cpp/lept/fpix1.c
            src/main/cpp/lept/rank.c
            src/main/cpp/lept/gplot.c
            src/main/cpp/lept/shear.c
            src/main/cpp/lept/gifio.c
            src/main/cpp/lept/binexpand.c
            src/main/cpp/lept/blend.c
            src/main/cpp/lept/dewarp1.c
            src/main/cpp/lept/readfile.c
            src/main/cpp/lept/pdfio1.c
            src/main/cpp/lept/convertfiles.c
            src/main/cpp/lept/jp2kiostub.c
            src/main/cpp/lept/binreduce.c
            src/main/cpp/lept/ptabasic.c
            src/main/cpp/lept/seedfill.c
            src/main/cpp/lept/pixlabel.c
            src/main/cpp/lept/ropiplow.c
            src/main/cpp/lept/jp2kheaderstub.c
            src/main/cpp/lept/fmorphauto.c
            src/main/cpp/lept/edge.c
            src/main/cpp/lept/graymorph.c
            src/main/cpp/lept/rotateorth.c
            src/main/cpp/lept/fhmtauto.c
            src/main/cpp/lept/pix5.c
            src/main/cpp/lept/psio1.c
            src/main/cpp/lept/map.c
            src/main/cpp/lept/pixacc.c
            src/main/cpp/lept/dwacomb.2.c
            src/main/cpp/lept/scalelow.c
            src/main/cpp/lept/pixcomp.c
            src/main/cpp/lept/textops.c
            src/main/cpp/lept/skew.c
            src/main/cpp/lept/pixafunc1.c
            src/main/cpp/lept/colorspace.c
            src/main/cpp/lept/flipdetect.c
            src/main/cpp/lept/pngiostub.c
            src/main/cpp/lept/runlength.c
            src/main/cpp/lept/dewarp2.c
            src/main/cpp/lept/boxfunc3.c
            src/main/cpp/lept/binarize.c
            src/main/cpp/lept/leptwin.c
            src/main/cpp/lept/recogident.c
            src/main/cpp/lept/rotateshear.c
            src/main/cpp/lept/compare.c
            src/main/cpp/lept/colormorph.c
            src/main/cpp/lept/pix2.c
            src/main/cpp/lept/pix1.c
            src/main/cpp/lept/colorquant1.c
            src/main/cpp/lept/psio2.c
            src/main/cpp/lept/pdfio2stub.c
            src/main/cpp/lept/partition.c
            src/main/cpp/lept/pngio.c
            src/main/cpp/lept/jp2kio.c
            src/main/cpp/lept/fpix2.c
            src/main/cpp/lept/fmorphgen.1.c
            src/main/cpp/lept/warper.c
            src/main/cpp/lept/correlscore.c
            src/main/cpp/lept/heap.c
            src/main/cpp/lept/ccthin.c
            src/main/cpp/lept/queue.c
            src/main/cpp/lept/colormap.c
            src/main/cpp/lept/paintcmap.c
            src/main/cpp/lept/roplow.c
            src/main/cpp/lept/list.c
            src/main/cpp/lept/sarray.c
            src/main/cpp/lept/classapp.c
            src/main/cpp/lept/utils.c
            src/main/cpp/lept/webpio.c
            src/main/cpp/lept/spixio.c
            src/main/cpp/lept/parseprotos.c
            src/main/cpp/lept/psio1stub.c
            src/main/cpp/lept/sel2.c
            src/main/cpp/lept/affine.c
            src/main/cpp/lept/sudoku.c
            src/main/cpp/lept/rop.c
            src/main/cpp/lept/gifiostub.c
            src/main/cpp/lept/tiffio.c
            src/main/cpp/lept/conncomp.c
            src/main/cpp/lept/pnmio.c
            src/main/cpp/lept/numafunc2.c
            src/main/cpp/lept/bilateral.c
            src/main/cpp/lept/grayquantlow.c
            src/main/cpp/lept/boxbasic.c
            src/main/cpp/lept/pixafunc2.c
            src/main/cpp/lept/bootnumgen1.c
            src/main/cpp/lept/colorseg.c
            src/main/cpp/lept/zlibmem.c
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
             src/main/cpp/native-lib/native-lib-jpeg.cpp
             src/main/cpp/native-lib/native-lib-lept.cpp)

# Specifies a path to native header files.
include_directories(
    src/main/cpp/z
    src/main/cpp/png
    src/main/cpp/jpeg
    src/main/cpp/tiff
    src/main/cpp/lept
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
                       com-reviso-marcello-ocrlab-lept
                       com-reviso-marcello-ocrlab-tiff
                       com-reviso-marcello-ocrlab-png
                       com-reviso-marcello-ocrlab-jpeg
                       com-reviso-marcello-ocrlab-z

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )

target_link_libraries( # Specifies the target library.
                       com-reviso-marcello-ocrlab-native-lib
                       com-reviso-marcello-ocrlab-lept

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
