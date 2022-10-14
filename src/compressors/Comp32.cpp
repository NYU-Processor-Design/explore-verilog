#include "CompressorTest.hpp"
#include "VComp32.h"

int main(void) {
  nyu::comp_test<VComp32, 3>();
  Verilated::threadContextp()->coveragep()->write("comp32.dat");
}
