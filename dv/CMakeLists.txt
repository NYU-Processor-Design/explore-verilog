set(rtl ${CMAKE_SOURCE_DIR}/rtl)

nyu_setup_test(
  TEST_NAME Comp22
  CPP_SOURCES Comp22.cpp
  SV_SOURCES ${rtl}/Comp22.sv
)

nyu_setup_test(
  TOP_MODULE Comp32
  CPP_SOURCES Comp32.cpp
  SV_SOURCES ${rtl}/Comp32.sv
)

nyu_setup_test(
  TOP_MODULE Comp42
  CPP_SOURCES Comp42.cpp
  SV_SOURCES ${rtl}/Comp42.sv ${rtl}/Comp32.sv
)

nyu_setup_test(
  TOP_MODULE Comp53
  CPP_SOURCES Comp53.cpp
  SV_SOURCES ${rtl}/Comp53.sv ${rtl}/Comp32.sv ${rtl}/Comp22.sv
)

nyu_setup_test(
  TOP_MODULE Comp73
  CPP_SOURCES Comp73.cpp
  SV_SOURCES ${rtl}/Comp73.sv ${rtl}/Comp32.sv
)
