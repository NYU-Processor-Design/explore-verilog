#include "CompressorTest.hpp"
#include "VComp53.h"

int main(void) {
  nyu::comp_test<VComp53, 5>();
  Verilated::threadContextp()->coveragep()->write("comp53.dat");
}
