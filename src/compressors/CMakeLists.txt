nyu_install_target(
  TARGET compressors
  FILES Comp22.sv Comp32.sv Comp42.sv Comp53.sv Comp73.sv
)

nyu_setup_test(
  TEST_NAME Comp22
  CPP_SOURCES Comp22.cpp
  SV_SOURCES Comp22.sv
)

nyu_setup_test(
  TOP_MODULE Comp32
  CPP_SOURCES Comp32.cpp
  SV_SOURCES Comp32.sv
)

nyu_setup_test(
  TOP_MODULE Comp42
  CPP_SOURCES Comp42.cpp
  SV_SOURCES Comp42.sv Comp32.sv
)

nyu_setup_test(
  TOP_MODULE Comp53
  CPP_SOURCES Comp53.cpp
  SV_SOURCES Comp53.sv Comp32.sv Comp22.sv
)

nyu_setup_test(
  TOP_MODULE Comp73
  CPP_SOURCES Comp73.cpp
  SV_SOURCES Comp73.sv Comp32.sv
)
