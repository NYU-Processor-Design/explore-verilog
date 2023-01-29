#include <bit>
#include <cassert>

#include <catch2/catch_test_macros.hpp>
#include <VComp42.h>

#include "CompressorTest.hpp"

TEST_CASE("Comp42") {
  VComp42 model;

  for(model.cin = 0; model.cin < 2; ++model.cin) {
    for(model.in = 0; model.in < (1 << 2); ++model.in) {
      model.eval();
      REQUIRE(
          model.out + 2 * model.cout == std::popcount(model.in) + model.cin);
    }
  }
}
