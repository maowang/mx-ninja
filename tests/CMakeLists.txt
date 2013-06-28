enable_testing()

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/tests.cmake)

if(NOT MSVC)
add_definitions(--coverage)
endif()

libmx_add_test(TestHttpClient)
libmx_add_test(TestThreadPool)
libmx_add_test(TestLock)
libmx_add_test(TestCoordSequence)
libmx_add_test(TestEnvelope)
libmx_add_test(TestByteOrder)
libmx_add_test(TestMXString)
libmx_add_test(TestSystem)
libmx_add_test(TestMXMath)
libmx_add_test(TestStream)
libmx_add_test(TestCondition)
