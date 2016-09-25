# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             z

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
             png

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
             native

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/lib1/native-lib.cpp )

# Specifies a path to native header files.
include_directories(
    src/main/cpp/z
    src/main/cpp/png
    src/main/cpp/lib1
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
                       png
                       z

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )

target_link_libraries( # Specifies the target library.
                       native
                       png

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
