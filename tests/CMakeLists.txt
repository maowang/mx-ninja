enable_testing()

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/tests.cmake)

libmx_add_test(TestHttpClient)
libmx_add_test(TestThreadPool)
