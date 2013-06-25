add_subdirectory(curl-7.30.0 libcurl)
if(MSVC)
add_subdirectory(pthread libpthread)
endif()
