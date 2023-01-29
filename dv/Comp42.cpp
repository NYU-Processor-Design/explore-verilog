#include <bit>

#include <catch2/catch_test_macros.hpp>
#include <VComp42.h>

TEST_CASE("Comp42") {
  VComp42 dut;

  for(dut.cin = 0; dut.cin < 2; ++dut.cin) {
    for(dut.in = 0; dut.in < (1 << 2); ++dut.in) {
      dut.eval();
      REQUIRE(dut.out + 2 * dut.cout == std::popcount(dut.in) + dut.cin);
    }
  }
}
