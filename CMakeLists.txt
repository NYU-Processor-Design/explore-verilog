cmake_minimum_required(VERSION 3.24)
project(explore-verilog VERSION 1.0)

option(BUILD_TESTS "Builds test binaries and adds them to CTest" TRUE)

set(VERILATOR_INCLUDE ${CMAKE_SOURCE_DIR}/src)

if(BUILD_TESTS)
  include(CTest)
  find_package(verilator CONFIG REQUIRED)
endif(BUILD_TESTS)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(cmake/NYUInstallTarget.cmake)
include(cmake/NYUSetupTest.cmake)

add_subdirectory(src)

configure_package_config_file(cmake/explore-verilog-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/explore-verilog-config.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/nyu
)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/explore-verilog-config-version.cmake
  COMPATIBILITY ExactVersion
  ARCH_INDEPENDENT
)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/explore-verilog-config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/explore-verilog-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/nyu
)
