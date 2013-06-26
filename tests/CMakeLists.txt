enable_testing()

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/tests.cmake)

add_definitions(--coverage)

libmx_add_test(TestHttpClient)
libmx_add_test(TestThreadPool)
libmx_add_test(TestLock)
libmx_add_test(TestCoordSequence)
libmx_add_test(TestEnvelope)
libmx_add_test(TestByteOrder)
libmx_add_test(TestMXString)
