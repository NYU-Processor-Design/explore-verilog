#include <catch2/catch_test_macros.hpp>
#include <VComp53.h>

#include "CompressorTest.hpp"

TEST_CASE("Comp53") {
  nyu::comp_test<VComp53, 5>();
}
