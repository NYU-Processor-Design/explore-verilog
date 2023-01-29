set(rtl ${CMAKE_SOURCE_DIR}/rtl)

find_package(Catch2 3 REQUIRED CONFIG)
find_package(nyu-util REQUIRED CONFIG)

add_executable(tests)
target_sources(tests PRIVATE
  Comp22.cpp Comp32.cpp Comp42.cpp Comp53.cpp Comp73.cpp
)
nyu_add_sv(tests
  ${rtl}/Comp22.sv ${rtl}/Comp32.sv ${rtl}/Comp42.sv ${rtl}/Comp53.sv
  ${rtl}/Comp73.sv
)
nyu_target_verilate(tests
  TOP_MODULES Comp22 Comp32 Comp42 Comp53 Comp73
  ARGS COVERAGE
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain nyu::covrecorder)
target_compile_features(tests PRIVATE cxx_std_23)

include(Catch)
catch_discover_tests(tests)
