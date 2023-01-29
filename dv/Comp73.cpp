#include <catch2/catch_test_macros.hpp>
#include <VComp73.h>

#include "CompressorTest.hpp"

TEST_CASE("Comp73") {
  nyu::comp_test<VComp73, 7>();
}
