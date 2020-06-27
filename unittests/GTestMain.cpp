#include "mlir/Dialect/RISCV/RISCVDialect.h"

#include "gtest/gtest.h"

int main(int argc, char **argv) {
  // Register dialect
  mlir::registerDialect<mlir::rv32i::RV32IDialect>();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
