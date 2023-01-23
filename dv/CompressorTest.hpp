#ifndef COMPRESSORTEST_HPP
#define COMPRESSORTEST_HPP

#include <bit>
#include <cassert>
#include <cstddef>

namespace nyu {

template <typename Model, size_t width> void comp_test() {
  Model model;
  model.in = 0;
  do {
    model.eval();
    assert(model.out == std::popcount(model.in));
  } while(++model.in > 0 && model.in < (1 << width));
}

} // namespace nyu
#endif // COMPRESSORTEST_HPP
