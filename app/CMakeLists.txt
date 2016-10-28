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
             com-reviso-marcello-ocrlab-tesseract

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
            src/main/cpp/tesseract/ccmain/superscript.cpp
            src/main/cpp/tesseract/ccmain/tesseractclass.cpp
            src/main/cpp/tesseract/ccmain/cubeclassifier.cpp
            src/main/cpp/tesseract/ccmain/pagewalk.cpp
            src/main/cpp/tesseract/ccmain/docqual.cpp
            src/main/cpp/tesseract/ccmain/tesseract_cube_combiner.cpp
            src/main/cpp/tesseract/ccmain/tessedit.cpp
            src/main/cpp/tesseract/ccmain/fixspace.cpp
            src/main/cpp/tesseract/ccmain/resultiterator.cpp
            src/main/cpp/tesseract/ccmain/thresholder.cpp
            src/main/cpp/tesseract/ccmain/tessbox.cpp
            src/main/cpp/tesseract/ccmain/cube_control.cpp
            src/main/cpp/tesseract/ccmain/ltrresultiterator.cpp
            src/main/cpp/tesseract/ccmain/osdetect.cpp
            src/main/cpp/tesseract/ccmain/recogtraining.cpp
            src/main/cpp/tesseract/ccmain/fixxht.cpp
            src/main/cpp/tesseract/ccmain/cube_reco_context.cpp
            src/main/cpp/tesseract/ccmain/reject.cpp
            src/main/cpp/tesseract/ccmain/applybox.cpp
            src/main/cpp/tesseract/ccmain/pagesegmain.cpp
            src/main/cpp/tesseract/ccmain/pageiterator.cpp
            src/main/cpp/tesseract/ccmain/adaptions.cpp
            src/main/cpp/tesseract/ccmain/control.cpp
            src/main/cpp/tesseract/ccmain/equationdetect.cpp
            src/main/cpp/tesseract/ccmain/tessvars.cpp
            src/main/cpp/tesseract/ccmain/pgedit.cpp
            src/main/cpp/tesseract/ccmain/paramsd.cpp
            src/main/cpp/tesseract/ccmain/werdit.cpp
            src/main/cpp/tesseract/ccmain/tfacepp.cpp
            src/main/cpp/tesseract/ccmain/output.cpp
            src/main/cpp/tesseract/ccmain/par_control.cpp
            src/main/cpp/tesseract/ccmain/paragraphs.cpp
            src/main/cpp/tesseract/ccutil/errcode.cpp
            src/main/cpp/tesseract/ccutil/unicharmap.cpp
            src/main/cpp/tesseract/ccutil/unicharset.cpp
            src/main/cpp/tesseract/ccutil/universalambigs.cpp
            src/main/cpp/tesseract/ccutil/tessdatamanager.cpp
            src/main/cpp/tesseract/ccutil/elst2.cpp
            src/main/cpp/tesseract/ccutil/ambigs.cpp
            src/main/cpp/tesseract/ccutil/tprintf.cpp
            src/main/cpp/tesseract/ccutil/bitvector.cpp
            src/main/cpp/tesseract/ccutil/clst.cpp
            src/main/cpp/tesseract/ccutil/params.cpp
            src/main/cpp/tesseract/ccutil/basedir.cpp
            src/main/cpp/tesseract/ccutil/ccutil.cpp
            src/main/cpp/tesseract/ccutil/unichar.cpp
            src/main/cpp/tesseract/ccutil/globaloc.cpp
            src/main/cpp/tesseract/ccutil/unicodes.cpp
            src/main/cpp/tesseract/ccutil/scanutils.cpp
            src/main/cpp/tesseract/ccutil/strngs.cpp
            src/main/cpp/tesseract/ccutil/elst.cpp
            src/main/cpp/tesseract/ccutil/indexmapbidi.cpp
            src/main/cpp/tesseract/ccutil/bits16.cpp
            src/main/cpp/tesseract/ccutil/mainblk.cpp
            src/main/cpp/tesseract/ccutil/memry.cpp
            src/main/cpp/tesseract/ccutil/serialis.cpp
            src/main/cpp/tesseract/dict/dawg.cpp
            src/main/cpp/tesseract/dict/hyphen.cpp
            src/main/cpp/tesseract/dict/permdawg.cpp
            src/main/cpp/tesseract/dict/stopper.cpp
            src/main/cpp/tesseract/dict/context.cpp
            src/main/cpp/tesseract/dict/dawg_cache.cpp
            src/main/cpp/tesseract/dict/trie.cpp
            src/main/cpp/tesseract/dict/dict.cpp
            src/main/cpp/tesseract/textord/alignedblob.cpp
            src/main/cpp/tesseract/textord/topitch.cpp
            src/main/cpp/tesseract/textord/pitsync1.cpp
            src/main/cpp/tesseract/textord/colfind.cpp
            src/main/cpp/tesseract/textord/tordmain.cpp
            src/main/cpp/tesseract/textord/strokewidth.cpp
            src/main/cpp/tesseract/textord/devanagari_processing.cpp
            src/main/cpp/tesseract/textord/textlineprojection.cpp
            src/main/cpp/tesseract/textord/ccnontextdetect.cpp
            src/main/cpp/tesseract/textord/colpartitionset.cpp
            src/main/cpp/tesseract/textord/colpartitiongrid.cpp
            src/main/cpp/tesseract/textord/makerow.cpp
            src/main/cpp/tesseract/textord/tospace.cpp
            src/main/cpp/tesseract/textord/drawedg.cpp
            src/main/cpp/tesseract/textord/tovars.cpp
            src/main/cpp/tesseract/textord/equationdetectbase.cpp
            src/main/cpp/tesseract/textord/tabfind.cpp
            src/main/cpp/tesseract/textord/tablefind.cpp
            src/main/cpp/tesseract/textord/scanedg.cpp
            src/main/cpp/tesseract/textord/textord.cpp
            src/main/cpp/tesseract/textord/baselinedetect.cpp
            src/main/cpp/tesseract/textord/workingpartset.cpp
            src/main/cpp/tesseract/textord/blkocc.cpp
            src/main/cpp/tesseract/textord/cjkpitch.cpp
            src/main/cpp/tesseract/textord/blobgrid.cpp
            src/main/cpp/tesseract/textord/edgblob.cpp
            src/main/cpp/tesseract/textord/linefind.cpp
            src/main/cpp/tesseract/textord/tablerecog.cpp
            src/main/cpp/tesseract/textord/sortflts.cpp
            src/main/cpp/tesseract/textord/underlin.cpp
            src/main/cpp/tesseract/textord/oldbasel.cpp
            src/main/cpp/tesseract/textord/fpchop.cpp
            src/main/cpp/tesseract/textord/wordseg.cpp
            src/main/cpp/tesseract/textord/tabvector.cpp
            src/main/cpp/tesseract/textord/edgloop.cpp
            src/main/cpp/tesseract/textord/drawtord.cpp
            src/main/cpp/tesseract/textord/imagefind.cpp
            src/main/cpp/tesseract/textord/bbgrid.cpp
            src/main/cpp/tesseract/textord/pithsync.cpp
            src/main/cpp/tesseract/textord/colpartition.cpp
            src/main/cpp/tesseract/textord/gap_map.cpp
            src/main/cpp/tesseract/classify/sampleiterator.cpp
            src/main/cpp/tesseract/classify/cutoffs.cpp
            src/main/cpp/tesseract/classify/normmatch.cpp
            src/main/cpp/tesseract/classify/errorcounter.cpp
            src/main/cpp/tesseract/classify/intfeaturemap.cpp
            src/main/cpp/tesseract/classify/normfeat.cpp
            src/main/cpp/tesseract/classify/intproto.cpp
            src/main/cpp/tesseract/classify/kdtree.cpp
            src/main/cpp/tesseract/classify/clusttool.cpp
            src/main/cpp/tesseract/classify/mastertrainer.cpp
            src/main/cpp/tesseract/classify/trainingsample.cpp
            src/main/cpp/tesseract/classify/blobclass.cpp
            src/main/cpp/tesseract/classify/adaptmatch.cpp
            src/main/cpp/tesseract/classify/intfeaturespace.cpp
            src/main/cpp/tesseract/classify/intmatcher.cpp
            src/main/cpp/tesseract/classify/fpoint.cpp
            src/main/cpp/tesseract/classify/shapeclassifier.cpp
            src/main/cpp/tesseract/classify/ocrfeatures.cpp
            src/main/cpp/tesseract/classify/trainingsampleset.cpp
            src/main/cpp/tesseract/classify/shapetable.cpp
            src/main/cpp/tesseract/classify/outfeat.cpp
            src/main/cpp/tesseract/classify/protos.cpp
            src/main/cpp/tesseract/classify/mfoutline.cpp
            src/main/cpp/tesseract/classify/classify.cpp
            src/main/cpp/tesseract/classify/mfdefs.cpp
            src/main/cpp/tesseract/classify/mfx.cpp
            src/main/cpp/tesseract/classify/adaptive.cpp
            src/main/cpp/tesseract/classify/float2int.cpp
            src/main/cpp/tesseract/classify/picofeat.cpp
            src/main/cpp/tesseract/classify/intfx.cpp
            src/main/cpp/tesseract/classify/featdefs.cpp
            src/main/cpp/tesseract/classify/mf.cpp
            src/main/cpp/tesseract/classify/intfeaturedist.cpp
            src/main/cpp/tesseract/classify/cluster.cpp
            src/main/cpp/tesseract/classify/tessclassifier.cpp
            src/main/cpp/tesseract/neural_networks/runtime/input_file_buffer.cpp
            src/main/cpp/tesseract/neural_networks/runtime/neuron.cpp
            src/main/cpp/tesseract/neural_networks/runtime/neural_net.cpp
            src/main/cpp/tesseract/neural_networks/runtime/sigmoid_table.cpp
            src/main/cpp/tesseract/ccstruct/pageres.cpp
            src/main/cpp/tesseract/ccstruct/publictypes.cpp
            src/main/cpp/tesseract/ccstruct/ocrpara.cpp
            src/main/cpp/tesseract/ccstruct/blobs.cpp
            src/main/cpp/tesseract/ccstruct/blamer.cpp
            src/main/cpp/tesseract/ccstruct/boxword.cpp
            src/main/cpp/tesseract/ccstruct/polyaprx.cpp
            src/main/cpp/tesseract/ccstruct/vecfuncs.cpp
            src/main/cpp/tesseract/ccstruct/mod128.cpp
            src/main/cpp/tesseract/ccstruct/stepblob.cpp
            src/main/cpp/tesseract/ccstruct/matrix.cpp
            src/main/cpp/tesseract/ccstruct/dppoint.cpp
            src/main/cpp/tesseract/ccstruct/genblob.cpp
            src/main/cpp/tesseract/ccstruct/rejctmap.cpp
            src/main/cpp/tesseract/ccstruct/blread.cpp
            src/main/cpp/tesseract/ccstruct/ccstruct.cpp
            src/main/cpp/tesseract/ccstruct/imagedata.cpp
            src/main/cpp/tesseract/ccstruct/params_training_featdef.cpp
            src/main/cpp/tesseract/ccstruct/ocrblock.cpp
            src/main/cpp/tesseract/ccstruct/polyblk.cpp
            src/main/cpp/tesseract/ccstruct/rect.cpp
            src/main/cpp/tesseract/ccstruct/pdblock.cpp
            src/main/cpp/tesseract/ccstruct/werd.cpp
            src/main/cpp/tesseract/ccstruct/split.cpp
            src/main/cpp/tesseract/ccstruct/ratngs.cpp
            src/main/cpp/tesseract/ccstruct/fontinfo.cpp
            src/main/cpp/tesseract/ccstruct/ocrrow.cpp
            src/main/cpp/tesseract/ccstruct/seam.cpp
            src/main/cpp/tesseract/ccstruct/normalis.cpp
            src/main/cpp/tesseract/ccstruct/points.cpp
            src/main/cpp/tesseract/ccstruct/otsuthr.cpp
            src/main/cpp/tesseract/ccstruct/blobbox.cpp
            src/main/cpp/tesseract/ccstruct/quspline.cpp
            src/main/cpp/tesseract/ccstruct/quadlsq.cpp
            src/main/cpp/tesseract/ccstruct/linlsq.cpp
            src/main/cpp/tesseract/ccstruct/statistc.cpp
            src/main/cpp/tesseract/ccstruct/coutln.cpp
            src/main/cpp/tesseract/ccstruct/detlinefit.cpp
            src/main/cpp/tesseract/ccstruct/boxread.cpp
            src/main/cpp/tesseract/cutil/cutil_class.cpp
            src/main/cpp/tesseract/cutil/danerror.cpp
            src/main/cpp/tesseract/cutil/emalloc.cpp
            src/main/cpp/tesseract/cutil/freelist.cpp
            src/main/cpp/tesseract/cutil/oldlist.cpp
            src/main/cpp/tesseract/cutil/callcpp.cpp
            src/main/cpp/tesseract/cutil/bitvec.cpp
            src/main/cpp/tesseract/cutil/structures.cpp
            src/main/cpp/tesseract/cutil/efio.cpp
            src/main/cpp/tesseract/cutil/listio.cpp
            src/main/cpp/tesseract/cutil/cutil.cpp
            src/main/cpp/tesseract/cube/tess_lang_model.cpp
            src/main/cpp/tesseract/cube/altlist.cpp
            src/main/cpp/tesseract/cube/cube_line_segmenter.cpp
            src/main/cpp/tesseract/cube/feature_chebyshev.cpp
            src/main/cpp/tesseract/cube/beam_search.cpp
            src/main/cpp/tesseract/cube/char_samp.cpp
            src/main/cpp/tesseract/cube/cube_object.cpp
            src/main/cpp/tesseract/cube/char_samp_enum.cpp
            src/main/cpp/tesseract/cube/word_altlist.cpp
            src/main/cpp/tesseract/cube/feature_hybrid.cpp
            src/main/cpp/tesseract/cube/con_comp.cpp
            src/main/cpp/tesseract/cube/word_size_model.cpp
            src/main/cpp/tesseract/cube/feature_bmp.cpp
            src/main/cpp/tesseract/cube/char_bigrams.cpp
            src/main/cpp/tesseract/cube/cube_line_object.cpp
            src/main/cpp/tesseract/cube/cube_tuning_params.cpp
            src/main/cpp/tesseract/cube/cached_file.cpp
            src/main/cpp/tesseract/cube/char_altlist.cpp
            src/main/cpp/tesseract/cube/hybrid_neural_net_classifier.cpp
            src/main/cpp/tesseract/cube/word_unigrams.cpp
            src/main/cpp/tesseract/cube/char_samp_set.cpp
            src/main/cpp/tesseract/cube/search_node.cpp
            src/main/cpp/tesseract/cube/classifier_factory.cpp
            src/main/cpp/tesseract/cube/word_list_lang_model.cpp
            src/main/cpp/tesseract/cube/cube_search_object.cpp
            src/main/cpp/tesseract/cube/bmp_8.cpp
            src/main/cpp/tesseract/cube/cube_utils.cpp
            src/main/cpp/tesseract/cube/char_set.cpp
            src/main/cpp/tesseract/cube/search_column.cpp
            src/main/cpp/tesseract/cube/conv_net_classifier.cpp
            src/main/cpp/tesseract/cube/tess_lang_mod_edge.cpp
            src/main/cpp/tesseract/viewer/svpaint.cpp
            src/main/cpp/tesseract/viewer/svmnode.cpp
            src/main/cpp/tesseract/viewer/scrollview.cpp
            src/main/cpp/tesseract/viewer/svutil.cpp
            src/main/cpp/tesseract/api/capi.cpp
            src/main/cpp/tesseract/api/renderer.cpp
            src/main/cpp/tesseract/api/pdfrenderer.cpp
            src/main/cpp/tesseract/api/baseapi.cpp
            # src/main/cpp/tesseract/api/tesseractmain.cpp
            src/main/cpp/tesseract/wordrec/segsearch.cpp
            src/main/cpp/tesseract/wordrec/wordrec.cpp
            src/main/cpp/tesseract/wordrec/render.cpp
            src/main/cpp/tesseract/wordrec/drawfx.cpp
            src/main/cpp/tesseract/wordrec/outlines.cpp
            src/main/cpp/tesseract/wordrec/associate.cpp
            src/main/cpp/tesseract/wordrec/lm_pain_points.cpp
            src/main/cpp/tesseract/wordrec/findseam.cpp
            src/main/cpp/tesseract/wordrec/language_model.cpp
            src/main/cpp/tesseract/wordrec/chopper.cpp
            src/main/cpp/tesseract/wordrec/gradechop.cpp
            src/main/cpp/tesseract/wordrec/wordclass.cpp
            src/main/cpp/tesseract/wordrec/lm_state.cpp
            src/main/cpp/tesseract/wordrec/params_model.cpp
            src/main/cpp/tesseract/wordrec/lm_consistency.cpp
            src/main/cpp/tesseract/wordrec/pieces.cpp
            src/main/cpp/tesseract/wordrec/plotedges.cpp
            src/main/cpp/tesseract/wordrec/tface.cpp
            src/main/cpp/tesseract/wordrec/chop.cpp
            src/main/cpp/tesseract/opencl/openclwrapper.cpp
)

target_compile_definitions(com-reviso-marcello-ocrlab-tesseract PRIVATE HAVE_CONFIG_H USE_STD_NAMESPACE)

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
             src/main/cpp/native-lib/native-lib-lept.cpp
)

# Specifies a path to native header files.
include_directories(
    src/main/cpp/z
    src/main/cpp/png
    src/main/cpp/jpeg
    src/main/cpp/tiff
    src/main/cpp/lept
    src/main/cpp/native-lib
    src/main/cpp/tesseract
    src/main/cpp/tesseract/ccmain
    src/main/cpp/tesseract/ccutil
    src/main/cpp/tesseract/dict
    src/main/cpp/tesseract/textord
    src/main/cpp/tesseract/classify
    src/main/cpp/tesseract/neural_networks
    src/main/cpp/tesseract/neural_networks/runtime
    src/main/cpp/tesseract/ccstruct
    src/main/cpp/tesseract/cutil
    src/main/cpp/tesseract/cube
    src/main/cpp/tesseract/viewer
    src/main/cpp/tesseract/api
    src/main/cpp/tesseract/wordrec
    src/main/cpp/tesseract/opencl
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

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )

target_link_libraries( # Specifies the target library.
                       com-reviso-marcello-ocrlab-tesseract
                       com-reviso-marcello-ocrlab-lept

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib})

target_link_libraries( # Specifies the target library.
                       com-reviso-marcello-ocrlab-native-lib
                       com-reviso-marcello-ocrlab-tesseract

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
