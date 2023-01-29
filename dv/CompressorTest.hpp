#ifndef COMPRESSORTEST_HPP
#define COMPRESSORTEST_HPP

#include <bit>
#include <cassert>
#include <cstddef>

#include <catch2/catch_test_macros.hpp>

namespace nyu {

template <typename Model, size_t width> void comp_test() {
  Model model;
  model.in = 0;
  do {
    model.eval();
    REQUIRE(model.out == std::popcount(model.in));
  } while(++model.in > 0 && model.in < (1 << width));
}

} // namespace nyu
#endif // COMPRESSORTEST_HPP
