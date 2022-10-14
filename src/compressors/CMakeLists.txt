setup_test(
  TEST_NAME Comp22
  CPP_SOURCES Comp22.cpp
  SV_SOURCES Comp22.sv
  TOP_MODULE Comp22
)

setup_test(
  TEST_NAME Comp32
  CPP_SOURCES Comp32.cpp
  SV_SOURCES Comp32.sv
  TOP_MODULE Comp32
)

setup_test(
  TEST_NAME Comp42
  CPP_SOURCES Comp42.cpp
  SV_SOURCES Comp42.sv Comp32.sv
  TOP_MODULE Comp42
)

setup_test(
  TEST_NAME Comp53
  CPP_SOURCES Comp53.cpp
  SV_SOURCES Comp53.sv Comp32.sv Comp22.sv
  TOP_MODULE Comp53
)

setup_test(
  TEST_NAME Comp73
  CPP_SOURCES Comp73.cpp
  SV_SOURCES Comp73.sv Comp32.sv
  TOP_MODULE Comp73
)
