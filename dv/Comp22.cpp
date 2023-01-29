#include <catch2/catch_test_macros.hpp>
#include <VComp22.h>

#include "CompressorTest.hpp"

TEST_CASE("Comp22") {
  nyu::comp_test<VComp22, 2>();
}
