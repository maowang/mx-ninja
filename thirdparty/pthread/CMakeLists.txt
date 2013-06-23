cmake_minimum_required(VERSION 2.6.2 FATAL_ERROR)
project( libpthread C )
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/libs)
add_library(libpthread STATIC ${CMAKE_CURRENT_SOURCE_DIR}/pthread.c)
