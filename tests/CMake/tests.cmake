function(libmx_add_test name)
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} libmx)
  add_test(${name} ${name})
endfunction()
