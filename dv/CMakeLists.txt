find_package(Catch2 3 REQUIRED CONFIG)
find_package(nyu-util REQUIRED CONFIG)

add_executable(tests)
target_sources(tests PRIVATE
  Comp22.cpp Comp32.cpp Comp42.cpp Comp53.cpp Comp73.cpp
)
nyu_link_sv(tests PRIVATE compressors)
nyu_target_verilate(tests
  TOP_MODULES Comp22 Comp32 Comp42 Comp53 Comp73
  ARGS COVERAGE
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain nyu::covrecorder)
target_compile_features(tests PRIVATE cxx_std_23)

include(Catch)
catch_discover_tests(tests)
