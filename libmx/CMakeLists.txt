file(GLOB_RECURSE BASE_CXX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/base/*.cpp)
file(GLOB_RECURSE BASE_H_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/base/*.h)
file(GLOB_RECURSE INTERNAL_CXX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/internal/*.cpp)
file(GLOB_RECURSE INTERNAL_C_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/internal/*.c)
file(GLOB_RECURSE INTERNAL_H_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/internal/*.h)

file(GLOB_RECURSE LIBMX_C_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
file(GLOB_RECURSE LIBMX_CXX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE LIBMX_H_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/libs)
add_definitions(-DCURL_STATICLIB)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/libs)

add_library(libmx STATIC ${LIBMX_C_SOURCE} ${LIBMX_CXX_SOURCE} ${LIBMX_H_SOURCE})

target_link_libraries(libmx libcurl)
target_link_libraries(libmx libpthread)

source_group("base\\Head Files" FILES ${BASE_H_SOURCE})
source_group("base\\Source Files" FILES ${BASE_CXX_SOURCE})
source_group("internal\\Head Files" FILES ${INTERNAL_H_SOURCE})
source_group("internal\\Source Files" FILES ${INTERNAL_C_SOURCE} ${INTERNAL_CXX_SOURCE})