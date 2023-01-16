cmake_minimum_required(VERSION 3.24)

set(CMAKE_TOOLCHAIN_FILE
  ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file"
)

project(explore-verilog VERSION 1.1.0)

find_package(nyu-cmake CONFIG REQUIRED)

add_library(compressors INTERFACE)
add_subdirectory(src)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

nyu_install_sv(
  EXPORT exploreVerilogTargets
  TARGETS compressors
  NAMESPACE nyu::
  EXPORT_DEST ${CMAKE_INSTALL_DATADIR}/explore-verilog
  SV_DEST ${CMAKE_INSTALL_DATADIR}/explore-verilog/rtl
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/explore-verilog-config-version.cmake
  COMPATIBILITY ExactVersion
  ARCH_INDEPENDENT
)
install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/explore-verilog-config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/explore-verilog-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/explore-verilog
)
