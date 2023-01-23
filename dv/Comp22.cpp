#include "CompressorTest.hpp"
#include "VComp22.h"

int main(void) {
  nyu::comp_test<VComp22, 2>();
  Verilated::threadContextp()->coveragep()->write("comp22.dat");
}
