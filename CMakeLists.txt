cmake_minimum_required(VERSION 3.24)
project(verilog-test)

option(BUILD_TESTS "Builds test binaries and adds them to CTest" TRUE)

if(BUILD_TESTS)
  include(CTest)
  find_package(verilator CONFIG REQUIRED)
endif(BUILD_TESTS)

set(VERILATOR_INCLUDE ${CMAKE_SOURCE_DIR}/src)

function(setup_test)
  set(single_args TEST_NAME TOP_MODULE)
  set(multi_args SV_SOURCES CPP_SOURCES)

  cmake_parse_arguments(PARSE_ARGV 0 ARG "" "${single_args}" "${multi_args}")

  if(BUILD_TESTS)
    add_executable(${ARG_TEST_NAME} ${ARG_CPP_SOURCES})
    target_compile_features(${ARG_TEST_NAME} PRIVATE cxx_std_20)
    verilate(${ARG_TEST_NAME}
      SOURCES ${ARG_SV_SOURCES}
      COVERAGE
      VERILATOR_ARGS -sv
      TOP_MODULE ${ARG_TOP_MODULE}
      INCLUDE_DIRS ${VERILATOR_INCLUDE}
    )
    add_test(
      NAME ${ARG_TEST_NAME}
      COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${ARG_TEST_NAME}
    )
  endif(BUILD_TESTS)
endfunction()

add_subdirectory(src)
