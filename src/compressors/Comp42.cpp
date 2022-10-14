#include <bit>
#include <cassert>

#include "VComp42.h"

int main(void) {
  VComp42 model;

  for(model.cin = 0; model.cin < 2; ++model.cin) {
    for(model.in = 0; model.in < (1 << 2); ++model.in) {
      model.eval();
      assert(model.out + 2 * model.cout == std::popcount(model.in) + model.cin);
    }
  }

  Verilated::threadContextp()->coveragep()->write("comp42.dat");
}
