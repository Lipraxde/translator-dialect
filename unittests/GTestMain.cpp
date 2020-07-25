#include "mlir/Dialect/RISCV/RISCVDialect.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/Dialect/Translation/TranslationDialect.h"

#include "gtest/gtest.h"

int main(int argc, char **argv) {
  // Register dialect
  mlir::registerDialect<mlir::StandardOpsDialect>();
  mlir::registerDialect<mlir::rv32i::RV32IDialect>();
  mlir::registerDialect<mlir::translation::TranslationDialect>();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
