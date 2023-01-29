#ifndef COMPRESSORTEST_HPP
#define COMPRESSORTEST_HPP

#include <bit>
#include <cassert>
#include <cstddef>

#include <catch2/catch_test_macros.hpp>

namespace nyu {

template <typename Model, size_t width> void comp_test() {
  Model dut;
  dut.in = 0;
  do {
    dut.eval();
    REQUIRE(dut.out == std::popcount(dut.in));
  } while(++dut.in > 0 && dut.in < (1 << width));
}

} // namespace nyu
#endif // COMPRESSORTEST_HPP
