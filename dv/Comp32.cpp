#include <catch2/catch_test_macros.hpp>
#include <VComp32.h>

#include "CompressorTest.hpp"

TEST_CASE("Comp32") {
  nyu::comp_test<VComp32, 3>();
}
