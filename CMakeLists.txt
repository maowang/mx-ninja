cmake_minimum_required(VERSION 2.6.2 FATAL_ERROR)
project(mx-ninja)

option(LIBMX_ENABLE_TEST "Enable build tests" ON)

include_directories(${CMAKE_SOURCE_DIR}/libmx)
include_directories(${CMAKE_SOURCE_DIR}/thirdparty)
include_directories(${CMAKE_SOURCE_DIR}/thirdParty/)
include_directories(${CMAKE_SOURCE_DIR}/thirdParty/curl-7.30.0/include/)
if(MSVC)
add_definitions(-DPTW32_STATIC_LIB)
include_directories(${CMAKE_SOURCE_DIR}/thirdParty/pthread/)
endif()

add_subdirectory(ThirdParty)
add_subdirectory(libmx)

if(LIBMX_ENABLE_TEST)
add_subdirectory(tests)
endif()
